
#include "gmock/gmock.h"
#include "../lib/solver.h"

TEST(Solver, ConstructorCheck) {
    ASSERT_NO_THROW(Solver solver);
}

TEST(Solver, CheckPeers) {
    Solver solver;

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            auto peers = solver.peers[row][col];
            EXPECT_EQ(peers.size(), 3*SIZE - 2*int(sqrt(float(SIZE))) - 1);

            for (auto i = peers.begin(); i != peers.end(); i++) {
                EXPECT_NE((*i).row*SIZE + (*i).col, row*SIZE + col);
            }
        }
    }
}

#define SOLVE_THE_BOARD(num, board_string) \
    TEST(Solver, ShouldSolve ## num) { \
        Board board; \
        Solver solver; \
        initializeBoardFromString(board, board_string); \
        std::cout << "Passed: " << board_string << std::endl; \
        ASSERT_TRUE(solver.solve(board)); \
    }

SOLVE_THE_BOARD( 0, ".........2..8.49.1...1.632......5.4.8..423..6.3.9......637.9...4.95.2..8.........");
/*
SOLVE_THE_BOARD( 1, "4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......");
SOLVE_THE_BOARD( 2, "52...6.........7.13...........4..8..6......5...........418.........3..2...87.....");
SOLVE_THE_BOARD( 3, "6.....8.3.4.7.................5.4.7.3..2.....1.6.......2.....5.....8.6......1....");
SOLVE_THE_BOARD( 4, "48.3............71.2.......7.5....6....2..8.............1.76...3.....4......5....");
SOLVE_THE_BOARD( 5, "....14....3....2...7..........9...3.6.1.............8.2.....1.4....5.6.....7.8...");
SOLVE_THE_BOARD( 6, "......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.");
SOLVE_THE_BOARD( 7, "6.2.5.........3.4..........43...8....1....2........7..5..27...........81...6.....");
SOLVE_THE_BOARD( 8, ".524.........7.1..............8.2...3.....6...9.5.....1.6.3...........897........");
SOLVE_THE_BOARD( 9, "6.2.5.........4.3..........43...8....1....2........7..5..27...........81...6.....");
SOLVE_THE_BOARD(10, ".923.........8.1...........1.7.4...........658.........6.5.2...4.....7.....9.....");
SOLVE_THE_BOARD(11, "6..3.2....5.....1..........7.26............543.........8.15........4.2........7..");
SOLVE_THE_BOARD(12, ".6.5.1.9.1...9..539....7....4.8...7.......5.8.817.5.3.....5.2............76..8...");
SOLVE_THE_BOARD(13, "..5...987.4..5...1..7......2...48....9.1.....6..2.....3..6..2.......9.7.......5..");
SOLVE_THE_BOARD(14, "3.6.7...........518.........1.4.5...7.....6.....2......2.....4.....8.3.....5.....");
SOLVE_THE_BOARD(15, "1.....3.8.7.4..............2.3.1...........958.........5.6...7.....8.2...4.......");
SOLVE_THE_BOARD(16, "6..3.2....4.....1..........7.26............543.........8.15........4.2........7..");
SOLVE_THE_BOARD(17, "....3..9....2....1.5.9..............1.2.8.4.6.8.5...2..75......4.1..6..3.....4.6.");
SOLVE_THE_BOARD(18, "45.....3....8.1....9...........5..9.2..7.....8.........1..4..........7.2...6..8..");
SOLVE_THE_BOARD(19, ".237....68...6.59.9.....7......4.97.3.7.96..2.........5..47.........2....8.......");
SOLVE_THE_BOARD(20, "..84...3....3.....9....157479...8........7..514.....2...9.6...2.5....4......9..56");
SOLVE_THE_BOARD(21, ".98.1....2......6.............3.2.5..84.........6.........4.8.93..5...........1..");
SOLVE_THE_BOARD(22, "..247..58..............1.4.....2...9528.9.4....9...1.........3.3....75..685..2...");
SOLVE_THE_BOARD(23, "4.....8.5.3..........7......2.....6.....5.4......1.......6.3.7.5..2.....1.9......");
SOLVE_THE_BOARD(24, ".2.3......63.....58.......15....9.3....7........1....8.879..26......6.7...6..7..4");
SOLVE_THE_BOARD(25, "1.....7.9.4...72..8.........7..1..6.3.......5.6..4..2.........8..53...7.7.2....46");
SOLVE_THE_BOARD(26, "4.....3.....8.2......7........1...8734.......6........5...6........1.4...82......");
SOLVE_THE_BOARD(27, ".......71.2.8........4.3...7...6..5....2..3..9........6...7.....8....4......5....");
SOLVE_THE_BOARD(28, "6..3.2....4.....8..........7.26............543.........8.15........8.2........7..");
SOLVE_THE_BOARD(29, ".47.8...1............6..7..6....357......5....1..6....28..4.....9.1...4.....2.69.");
SOLVE_THE_BOARD(30, "......8.17..2........5.6......7...5..1....3...8.......5......2..4..8....6...3....");
SOLVE_THE_BOARD(31, "38.6.......9.......2..3.51......5....3..1..6....4......17.5..8.......9.......7.32");
SOLVE_THE_BOARD(32, "...5...........5.697.....2...48.2...25.1...3..8..3.........4.7..13.5..9..2...31..");
SOLVE_THE_BOARD(33, ".2.......3.5.62..9.68...3...5..........64.8.2..47..9....3.....1.....6...17.43....");
SOLVE_THE_BOARD(34, ".8..4....3......1........2...5...4.69..1..8..2...........3.9....6....5.....2.....");
SOLVE_THE_BOARD(35, "..8.9.1...6.5...2......6....3.1.7.5.........9..4...3...5....2...7...3.8.2..7....4");
SOLVE_THE_BOARD(36, "4.....5.8.3..........7......2.....6.....5.8......1.......6.3.7.5..2.....1.8......");
SOLVE_THE_BOARD(37, "1.....3.8.6.4..............2.3.1...........958.........5.6...7.....8.2...4.......");
SOLVE_THE_BOARD(38, "1....6.8..64..........4...7....9.6...7.4..5..5...7.1...5....32.3....8...4........");
SOLVE_THE_BOARD(39, "249.6...3.3....2..8.......5.....6......2......1..4.82..9.5..7....4.....1.7...3...");
SOLVE_THE_BOARD(40, "...8....9.873...4.6..7.......85..97...........43..75.......3....3...145.4....2..1");
SOLVE_THE_BOARD(41, "...5.1....9....8...6.......4.1..........7..9........3.8.....1.5...2..4.....36....");
SOLVE_THE_BOARD(42, "......8.16..2........7.5......6...2..1....3...8.......2......7..3..8....5...4....");
SOLVE_THE_BOARD(43, ".476...5.8.3.....2.....9......8.5..6...1.....6.24......78...51...6....4..9...4..7");
SOLVE_THE_BOARD(44, ".....7.95.....1...86..2.....2..73..85......6...3..49..3.5...41724................");
SOLVE_THE_BOARD(45, ".4.5.....8...9..3..76.2.....146..........9..7.....36....1..4.5..6......3..71..2..");
SOLVE_THE_BOARD(46, ".834.........7..5...........4.1.8..........27...3.....2.6.5....5.....8........1..");
SOLVE_THE_BOARD(47, "..9.....3.....9...7.....5.6..65..4.....3......28......3..75.6..6...........12.3.8");
SOLVE_THE_BOARD(48, ".26.39......6....19.....7.......4..9.5....2....85.....3..2..9..4....762.........4");
SOLVE_THE_BOARD(49, "2.3.8....8..7...........1...6.5.7...4......3....1............82.5....6...1.......");
SOLVE_THE_BOARD(50, "6..3.2....1.....5..........7.26............843.........8.15........8.2........7..");
SOLVE_THE_BOARD(51, "1.....9...64..1.7..7..4.......3.....3.89..5....7....2.....6.7.9.....4.1....129.3.");
SOLVE_THE_BOARD(52, ".........9......84.623...5....6...453...1...6...9...7....1.....4.5..2....3.8....9");
SOLVE_THE_BOARD(53, ".2....5938..5..46.94..6...8..2.3.....6..8.73.7..2.........4.38..7....6..........5");
SOLVE_THE_BOARD(54, "9.4..5...25.6..1..31......8.7...9...4..26......147....7.......2...3..8.6.4.....9.");
SOLVE_THE_BOARD(55, "...52.....9...3..4......7...1.....4..8..453..6...1...87.2........8....32.4..8..1.");
SOLVE_THE_BOARD(56, "53..2.9...24.3..5...9..........1.827...7.........981.............64....91.2.5.43.");
SOLVE_THE_BOARD(57, "1....786...7..8.1.8..2....9........24...1......9..5...6.8..........5.9.......93.4");
SOLVE_THE_BOARD(58, "....5...11......7..6.....8......4.....9.1.3.....596.2..8..62..7..7......3.5.7.2..");
SOLVE_THE_BOARD(59, ".47.2....8....1....3....9.2.....5...6..81..5.....4.....7....3.4...9...1.4..27.8..");
SOLVE_THE_BOARD(60, "......94.....9...53....5.7..8.4..1..463...........7.8.8..7.....7......28.5.26....");
SOLVE_THE_BOARD(61, ".2......6....41.....78....1......7....37.....6..412....1..74..5..8.5..7......39..");
SOLVE_THE_BOARD(62, "1.....3.8.6.4..............2.3.1...........758.........7.5...6.....8.2...4.......");
SOLVE_THE_BOARD(63, "2....1.9..1..3.7..9..8...2.......85..6.4.........7...3.2.3...6....5.....1.9...2.5");
SOLVE_THE_BOARD(64, "..7..8.....6.2.3...3......9.1..5..6.....1.....7.9....2........4.83..4...26....51.");
SOLVE_THE_BOARD(65, "...36....85.......9.4..8........68.........17..9..45...1.5...6.4....9..2.....3...");
SOLVE_THE_BOARD(66, "34.6.......7.......2..8.57......5....7..1..2....4......36.2..1.......9.......7.82");
SOLVE_THE_BOARD(67, "......4.18..2........6.7......8...6..4....3...1.......6......2..5..1....7...3....");
SOLVE_THE_BOARD(68, ".4..5..67...1...4....2.....1..8..3........2...6...........4..5.3.....8..2........");
SOLVE_THE_BOARD(69, ".......4...2..4..1.7..5..9...3..7....4..6....6..1..8...2....1..85.9...6.....8...3");
SOLVE_THE_BOARD(70, "8..7....4.5....6............3.97...8....43..5....2.9....6......2...6...7.71..83.2");
SOLVE_THE_BOARD(71, ".8...4.5....7..3............1..85...6.....2......4....3.26............417........");
SOLVE_THE_BOARD(72, "....7..8...6...5...2...3.61.1...7..2..8..534.2..9.......2......58...6.3.4...1....");
SOLVE_THE_BOARD(73, "......8.16..2........7.5......6...2..1....3...8.......2......7..4..8....5...3....");
SOLVE_THE_BOARD(74, ".2..........6....3.74.8.........3..2.8..4..1.6..5.........1.78.5....9..........4.");
SOLVE_THE_BOARD(75, ".52..68.......7.2.......6....48..9..2..41......1.....8..61..38.....9...63..6..1.9");
SOLVE_THE_BOARD(76, "....1.78.5....9..........4..2..........6....3.74.8.........3..2.8..4..1.6..5.....");
SOLVE_THE_BOARD(77, "1.......3.6.3..7...7...5..121.7...9...7........8.1..2....8.64....9.2..6....4.....");
SOLVE_THE_BOARD(78, "4...7.1....19.46.5.....1......7....2..2.3....847..6....14...8.6.2....3..6...9....");
SOLVE_THE_BOARD(79, "......8.17..2........5.6......7...5..1....3...8.......5......2..3..8....6...4....");
SOLVE_THE_BOARD(80, "963......1....8......2.5....4.8......1....7......3..257......3...9.2.4.7......9..");
SOLVE_THE_BOARD(81, "15.3......7..4.2....4.72.....8.........9..1.8.1..8.79......38...........6....7423");
SOLVE_THE_BOARD(82, "..........5724...98....947...9..3...5..9..12...3.1.9...6....25....56.....7......6");
SOLVE_THE_BOARD(83, "....75....1..2.....4...3...5.....3.2...8...1.......6.....1..48.2........7........");
SOLVE_THE_BOARD(84, "6.....7.3.4.8.................5.4.8.7..2.....1.3.......2.....5.....7.9......1....");
SOLVE_THE_BOARD(85, "....6...4..6.3....1..4..5.77.....8.5...8.....6.8....9...2.9....4....32....97..1..");
SOLVE_THE_BOARD(86, ".32.....58..3.....9.428...1...4...39...6...5.....1.....2...67.8.....4....95....6.");
SOLVE_THE_BOARD(87, "...5.3.......6.7..5.8....1636..2.......4.1.......3...567....2.8..4.7.......2..5..");
SOLVE_THE_BOARD(88, ".5.3.7.4.1.........3.......5.8.3.61....8..5.9.6..1........4...6...6927....2...9..");
SOLVE_THE_BOARD(89, "..5..8..18......9.......78....4.....64....9......53..2.6.........138..5....9.714.");
SOLVE_THE_BOARD(90, "..........72.6.1....51...82.8...13..4.........37.9..1.....238..5.4..9.........79.");
SOLVE_THE_BOARD(91, "...658.....4......12............96.7...3..5....2.8...3..19..8..3.6.....4....473..");
SOLVE_THE_BOARD(92, ".2.3.......6..8.9.83.5........2...8.7.9..5........6..4.......1...1...4.22..7..8.9");
SOLVE_THE_BOARD(93, ".5..9....1.....6.....3.8.....8.4...9514.......3....2..........4.8...6..77..15..6.");
SOLVE_THE_BOARD(94, ".....2.......7...17..3...9.8..7......2.89.6...13..6....9..5.824.....891..........");
SOLVE_THE_BOARD(95, "3...8.......7....51..............36...2..4....7...........6.13..452...........8..");
*/
