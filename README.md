==2333== LEAK SUMMARY:
==2333==    definitely lost: 4,194,233 bytes in 3 blocks
==2333==    indirectly lost: 0 bytes in 0 blocks
==2333==      possibly lost: 200,010,001 bytes in 1 blocks
==2333==    still reachable: 528,423 bytes in 3 blocks
==2333==         suppressed: 25,004 bytes in 372 blocks
==2333== Reachable blocks (those to which a pointer was found) are not shown.
==2333== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==2333==
==2333== For counts of detected and suppressed errors, rerun with: -v
==2333== ERROR SUMMARY: 190856577 errors from 14 contexts (suppressed: 145 from 49)
[1]    2333 segmentation fault  valgrind --tool=memcheck --leak-check=full --track-origins=yes  ./a.out
===
