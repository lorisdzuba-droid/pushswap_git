#!/usr/bin/env bash
# tester_debug.sh  -- robust batch tester with diagnostics for "only first batch" problem

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"

RED="\033[1;31m"; GREEN="\033[1;32m"; YELLOW="\033[1;33m"; BLUE="\033[1;34m"
CYAN="\033[1;36m"; BOLD="\033[1m"; RESET="\033[0m"

# helper: uppercase in a portable way
toupper() { echo "$1" | tr '[:lower:]' '[:upper:]'; }

progress_bar() {
    local current=$1 total=$2 moves=$3 eta_sec=$4 width=40
    local percent=0 filled empty bar space
    (( total > 0 )) && percent=$(( current * 100 / total ))
    filled=$(( percent * width / 100 )); empty=$(( width - filled ))
    bar=$(printf "%0.s#" $(seq 1 $filled 2>/dev/null) 2>/dev/null)
    space=$(printf "%0.s-" $(seq 1 $empty 2>/dev/null) 2>/dev/null)
    printf "\r${CYAN}Progress:${RESET} [%s%s] %3d%% (%d/%d) - Moves: %d - ETA: %2ds" \
        "$bar" "$space" "$percent" "$current" "$total" "$moves" "$eta_sec"
}

echo -e "${BLUE}${BOLD}Checking for forbidden calloc calls...${RESET}"

FORBIDDEN_FOUND=0

# directories to check
SEARCH_DIRS=( "./" "./bonus" "./libft" )

# Use grep to find "calloc(" but exclude:
#   - ft_calloc
#   - lines starting with comment markers or containing /* ... */
#   - occurrences inside strings
for DIR in "${SEARCH_DIRS[@]}"; do
    if [[ -d "$DIR" ]]; then
        while IFS= read -r line; do
            FILE=$(echo "$line" | cut -d: -f1)
            LINENO=$(echo "$line" | cut -d: -f2)
            CONTENT=$(echo "$line" | cut -d: -f3-)

            # skip ft_calloc, comments, strings
            if grep -q "ft_calloc" <<< "$CONTENT"; then continue; fi
            if grep -qE '^\s*(//|/\*|\*)' <<< "$CONTENT"; then continue; fi
            if grep -qE '"[^"]*calloc\(' <<< "$CONTENT"; then continue; fi

            # true forbidden calloc
            if grep -q "calloc(" <<< "$CONTENT"; then
                echo -e "${RED}❌ Forbidden calloc found:${RESET} $FILE:$LINENO"
                echo "     $CONTENT"
                FORBIDDEN_FOUND=1
            fi
        done < <(grep -RIn "calloc(" "$DIR" --include \*.c --include \*.h 2>/dev/null)
    fi
done

if (( FORBIDDEN_FOUND > 0 )); then
    echo -e "${RED}${BOLD}Error: raw calloc calls detected. Use ft_calloc only.${RESET}"
    exit 1
else
    echo -e "${GREEN}${BOLD}✔ No forbidden calloc calls detected.${RESET}\n"
fi

invalid_tests() {
    echo -e "${BLUE}${BOLD}Running invalid input tests...${RESET}"
    local FAIL=0

    #
    # INTERNAL HELPER FOR PUSH_SWAP
    #
    run_invalid_case() {
        local args="$1" expect="$2" label="$3"
        read -a tmp_args <<< "$args"
        OUT=$("$PUSH_SWAP" "${tmp_args[@]}" 2>&1 || true)
        if [[ "$expect" == "ERR" ]]; then
            if [[ "$OUT" != *"Error"* ]]; then
                echo -e "${RED}❌ FAIL: $label (expected Error)${RESET}"
                ((FAIL++))
            else
                echo -e "${GREEN}✔ PASS: $label${RESET}"
            fi
        else
            if [[ -n "$OUT" ]]; then
                echo -e "${RED}❌ FAIL: $label (expected empty output)${RESET}"
                ((FAIL++))
            else
                echo -e "${GREEN}✔ PASS: $label${RESET}"
            fi
        fi
    }

    #
    # PUSH_SWAP ARGUMENT TESTS
    #
    run_invalid_case "abc 123" ERR "Invalid characters"
    run_invalid_case "1e" ERR "Invalid characters #2"
    run_invalid_case "1 2 3 5 -1e" ERR "Invalid characters #3"
    run_invalid_case "2147483647" NONE "INT_MAX"
    run_invalid_case "-2147483648" NONE "INT_MIN"
    run_invalid_case "2147483648" ERR "Overflow INT_MAX"
    run_invalid_case "-2147483649" ERR "Overflow INT_MIN"
    run_invalid_case "1 2 2 3" ERR "Duplicate numbers"
    run_invalid_case "" NONE "Empty input (must output nothing)"
    run_invalid_case "1" NONE "Single digit (must output nothing)"
    run_invalid_case "1 2 3 4 5" NONE "Already sorted input (must output nothing)"
    run_invalid_case "1-" ERR "Trailing invalid characters '1-'"
    run_invalid_case "0-" ERR "Trailing invalid characters '0-'"
    run_invalid_case "0-1+2" ERR "Weird Trailing (no spaces)"
    run_invalid_case "\"1 2 3\" -1 -2 5" ERR "Mixed quoted + unquoted"
    run_invalid_case " "1" 2 5" NONE "Valid quoted + unquoted"
    run_invalid_case "+1" NONE "Positive single digit"
    run_invalid_case "+0" NONE "Positive zero"
    run_invalid_case "-0" NONE "Negative zero"
    run_invalid_case "++1 2 3" ERR "Duplicate signs"
    run_invalid_case "-2 -1 -0 +1 +2 +3" NONE "Many signs"
    run_invalid_case "+++++++1 2 3" ERR "Many Duplicate signs"
    run_invalid_case "18446744073709551615 2 3" ERR "Unsigned long long"
    run_invalid_case "11111111111111111111111111111 2 3" ERR "Very Big Number overflow"
    run_invalid_case "-9999999999999999999999999999 2 3" ERR "Very Negative Number overflow"
    #
    # -----------------------------------------
    # CHECKER TESTS ADDED HERE
    # -----------------------------------------
    #
    if [[ ! -x "$CHECKER" ]]; then
        echo -e "${YELLOW}⚠ Checker not found or not executable. Skipping checker tests.${RESET}"
    else
        echo -e "${CYAN}${BOLD}Running checker invalid tests...${RESET}"

        #
        # Helper for checking checker output
        #
        run_checker_arg_test() {
            local args="$1" expect="$2" label="$3"
            read -a tmp_args <<< "$args"
            OUT=$("$CHECKER" "${tmp_args[@]}" 2>&1 < /dev/null || true)

            if [[ "$expect" == "ERR" ]]; then
                [[ "$OUT" == "Error" ]] && \
                    echo -e "${GREEN}✔ PASS: $label${RESET}" || {
                        echo -e "${RED}❌ FAIL: $label (expected Error, got '$OUT')${RESET}"
                        ((FAIL++))
                    }
            else
                [[ "$OUT" == "OK" ]] && \
                    echo -e "${GREEN}✔ PASS: $label${RESET}" || {
                        echo -e "${RED}❌ FAIL: $label (expected OK, got '$OUT')${RESET}"
                        ((FAIL++))
                    }
            fi
        }

        #
        # Same invalid argument tests for checker
        #
        run_checker_arg_test "abc 123" ERR "Checker invalid chars"
        run_checker_arg_test "1e" ERR "Checker invalid chars #2"
        run_checker_arg_test "2147483648" ERR "Checker overflow"
        run_checker_arg_test "1 2 2" ERR "Checker duplicates"

        #
        # Sorted input, no stdin → OK
        #
        run_checker_arg_test "1 2 3 4 5" OK "Checker: already sorted OK"

        #
        # Valid args + invalid stdin command → must ERROR
        #
        OUT=$("$CHECKER" 4 2 1 3 <<< "ttttt" 2>&1 || true)
        if [[ "$OUT" == "Error" ]]; then
            echo -e "${GREEN}✔ PASS: Checker invalid stdin instruction${RESET}"
        else
            echo -e "${RED}❌ FAIL: Checker invalid stdin instruction (expected Error, got '$OUT')${RESET}"
            ((FAIL++))
        fi

        #
        # Valid args + correct instruction (ra) → must output OK
        #
        OUT=$("$CHECKER" 4 1 2 3 <<< "ra" 2>&1 || true)
        if [[ "$OUT" == "OK" ]]; then
            echo -e "${GREEN}✔ PASS: Checker valid 'ra' instruction${RESET}"
        else
            echo -e "${RED}❌ FAIL: Checker valid 'ra' instruction (expected OK, got '$OUT')${RESET}"
            ((FAIL++))
        fi
    fi


    (( FAIL == 0 )) && \
        echo -e "${GREEN}${BOLD}All invalid tests passed!${RESET}\n" || \
        echo -e "${RED}${BOLD}$FAIL invalid tests failed.${RESET}\n"
}

# run one configured batch
run_test_set() {
    local SIZE="$1" USE_CHECKER="$2" TESTS="$3" MAX_MOVES="$4" LOG_OVER="$5"

    echo -e "${BLUE}${BOLD}Running ${TESTS} tests for size ${SIZE} (checker=${USE_CHECKER}, max_moves=${MAX_MOVES}, log_over=${LOG_OVER})...${RESET}"
    if (( TESTS <= 0 )); then
        echo -e "${YELLOW}Zero tests requested; skipping.${RESET}"
        SUMMARY+=("${SIZE}|0|0|0|0|0|0|0|0|0")
        return
    fi

    local out_file="${SIZE}_ps_over_max.txt"
    if [[ "$(toupper "$LOG_OVER")" == "Y" ]]; then : >"$out_file"; else rm -f "$out_file" 2>/dev/null || true; fi

    local total_moves=0 min_moves=0 max_moves=0 total_time_ms=0 min_time_ms=0 max_time_ms=0 over_max=0 chk_err=0

    for ((t=1; t<=TESTS; t++)); do
        # create reproducible single sequence string and same args array for both executables
        numbers=$(shuf -i 0-"$SIZE" -n "$SIZE" | tr '\n' ' ')
        # split into array preserving tokens exactly
        IFS=' ' read -r -a ARGS <<< "$numbers"

        TMP=$(mktemp /tmp/pushmoves.XXXXXX) || { echo "mktemp failed"; exit 1; }
        START_NS=$(date +%s%N)
        "$PUSH_SWAP" "${ARGS[@]}" >"$TMP" 2>/dev/null || true
        END_NS=$(date +%s%N)

        elapsed_ms=$(( (END_NS - START_NS) / 1000000 ))
        moves=$(wc -l <"$TMP" | tr -d ' ')

        (( total_moves += moves ))
        (( total_time_ms += elapsed_ms ))

        if (( t == 1 )); then min_moves=$moves; max_moves=$moves; min_time_ms=$elapsed_ms; max_time_ms=$elapsed_ms; else
            (( moves < min_moves )) && min_moves=$moves
            (( moves > max_moves )) && max_moves=$moves
            (( elapsed_ms < min_time_ms )) && min_time_ms=$elapsed_ms
            (( elapsed_ms > max_time_ms )) && max_time_ms=$elapsed_ms
        fi

        if (( MAX_MOVES >= 0 && moves > MAX_MOVES )); then (( over_max++ )); [[ "$(toupper "$LOG_OVER")" == "Y" ]] && echo "$numbers" >>"$out_file"; fi

        if [[ "$(toupper "$USE_CHECKER")" == "Y" ]]; then
            if [[ -x "$CHECKER" ]]; then
                res=$("$CHECKER" "${ARGS[@]}" <"$TMP" 2>/dev/null || echo "ERR")
                [[ "$res" != "OK" ]] && (( chk_err++ ))
            else
                (( chk_err++ ))
            fi
        fi

        avg_per=$(( total_time_ms / t ))
        eta=$(( avg_per * (TESTS - t) / 1000 ))
        progress_bar "$t" "$TESTS" "$moves" "$eta"

        rm -f "$TMP"
    done

    avg_moves=0 avg_time_ms=0 exceed_pct=0
    (( TESTS > 0 )) && avg_moves=$(( total_moves / TESTS )) && avg_time_ms=$(( total_time_ms / TESTS )) && exceed_pct=$(( 100 * over_max / TESTS ))

    echo -e "\n${GREEN}${BOLD}--- Results for size $SIZE ---${RESET}"
	echo -e "Best moves:          ${GREEN}$min_moves${RESET}"
	echo -e "Worst moves:         ${RED}$max_moves${RESET}"
	echo -e "Average moves:       ${CYAN}$avg_moves${RESET}"
	echo -e "Fastest exec:        ${GREEN}${min_time_ms}ms${RESET}"
	echo -e "Slowest exec:        ${RED}${max_time_ms}ms${RESET}"
	echo -e "Average exec:        ${CYAN}${avg_time_ms}ms${RESET}"
	echo -e "Checker errors:      ${YELLOW}$chk_err${RESET}"

	# Format exceed_pct with 2 decimals
	exceed_float=$(printf "%.2f" "$exceed_pct")

	if (( over_max > 0 )); then
	    echo -e "Exceeded max moves:  ${YELLOW}$over_max${RESET} (${exceed_float}%)  ${YELLOW}\033[1m🚧 [WARNING]\033[0m"
	else
	    echo -e "Exceeded max moves:  ${YELLOW}$over_max${RESET} (${exceed_float}%)"
	fi

	# Save summary entry
	SUMMARY+=("${SIZE}|${avg_moves}|${min_moves}|${max_moves}|${avg_time_ms}|${min_time_ms}|${max_time_ms}|${over_max}|${chk_err}|${exceed_float}")
}

# ---------------- Interactive config ----------------
read -r -p "Run invalid input tests? (Y/n): " INV
INV=${INV:-Y}; INV=$(toupper "$INV")
if [[ "$INV" == "Y" ]]; then
    [[ -x "$PUSH_SWAP" ]] || { echo -e "${RED}push_swap not executable at: $PUSH_SWAP${RESET}"; exit 1; }
    invalid_tests
fi

read -r -p "How many test batches? " NUM_BATCHES
NUM_BATCHES=${NUM_BATCHES:-0}
if ! [[ "$NUM_BATCHES" =~ ^[0-9]+$ ]]; then echo -e "${RED}Invalid number of batches.${RESET}"; exit 1; fi

# arrays
TEST_SIZES=(); TEST_CHECKER=(); TEST_COUNTS=(); TEST_MAX_MOVES=(); TEST_LOG=()

for ((bi=0; bi<NUM_BATCHES; bi++)); do
    echo -e "${CYAN}--- Configure batch $((bi+1)) ---${RESET}"
    read -r -p "How many numbers? " N
    N=${N:-5}
    if ! [[ "$N" =~ ^[0-9]+$ && "$N" -ge 1 ]]; then echo -e "${YELLOW}Invalid size; defaulting to 5.${RESET}"; N=5; fi

    read -r -p "Use checker? (Y/n): " C
    C=${C:-Y}; C=$(toupper "$C")

    read -r -p "How many tests? " T
    T=${T:-10}
    if ! [[ "$T" =~ ^[0-9]+$ ]]; then echo -e "${YELLOW}Invalid tests; defaulting to 10.${RESET}"; T=10; fi

    read -r -p "Max allowed moves? " M
    M=${M:--1}; if ! [[ "$M" =~ ^-?[0-9]+$ ]]; then echo -e "${YELLOW}Invalid max moves; defaulting to -1 (disabled).${RESET}"; M=-1; fi

    read -r -p "Log exceeding max_move cases? (Y/n): " L
    L=${L:-Y}; L=$(toupper "$L")

    TEST_SIZES+=("$N")
    TEST_CHECKER+=("$C")
    TEST_COUNTS+=("$T")
    TEST_MAX_MOVES+=("$M")
    TEST_LOG+=("$L")
    echo ""
done

# ---------------- Debug: show what will run ----------------
echo -e "${MAGENTA}${BOLD}BATCH CONFIG: NUM_BATCHES=${NUM_BATCHES}${RESET}"
for ((i=0; i<NUM_BATCHES; i++)); do
    echo -e "  batch $i => size=${TEST_SIZES[$i]}, checker=${TEST_CHECKER[$i]}, tests=${TEST_COUNTS[$i]}, max_moves=${TEST_MAX_MOVES[$i]}, log=${TEST_LOG[$i]}"
done
echo ""

# ---------------- Run all batches ----------------
SUMMARY=()
for ((i=0; i<NUM_BATCHES; i++)); do
    run_test_set "${TEST_SIZES[$i]}" "${TEST_CHECKER[$i]}" "${TEST_COUNTS[$i]}" "${TEST_MAX_MOVES[$i]}" "${TEST_LOG[$i]}"
done

# ---------------- Summary ----------------
echo -e "\n${BLUE}${BOLD}============= SUMMARY =============${RESET}"
printf "%-8s %-10s %-10s %-10s %-12s %-12s %-12s %-10s %-10s %-8s\n" \
"Size" "AvgMoves" "Best" "Worst" "AvgTime" "Fastest" "Slowest" "OverMax" "ChkErr" "Odds%"
for ENTRY in "${SUMMARY[@]}"; do
    IFS="|" read -r S AM BM WM AT FT ST OM CE OP <<< "$ENTRY"
    printf "%-8s %-10s %-10s %-10s %-12sms %-12sms %-12sms %-10s %-10s %-10.2f\n" \
    "$S" "$AM" "$BM" "$WM" "$AT" "$FT" "$ST" "$OM" "$CE" "$OP"
done
echo -e "${BLUE}${BOLD}====================================${RESET}\n"
