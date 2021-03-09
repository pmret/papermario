.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPiGetCmdQueue
/* 46950 8006B550 3C038009 */  lui       $v1, %hi(__osPiDevMgr)
/* 46954 8006B554 8C633D50 */  lw        $v1, %lo(__osPiDevMgr)($v1)
/* 46958 8006B558 10600003 */  beqz      $v1, .L8006B568
/* 4695C 8006B55C 00001021 */   addu     $v0, $zero, $zero
/* 46960 8006B560 3C028009 */  lui       $v0, %hi(__osPiDevMgr + 8)
/* 46964 8006B564 8C423D58 */  lw        $v0, %lo(__osPiDevMgr + 8)($v0)
.L8006B568:
/* 46968 8006B568 03E00008 */  jr        $ra
/* 4696C 8006B56C 00000000 */   nop
