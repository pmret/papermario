.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel crash_create_monitor
/* 7CB0 8002C8B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7CB4 8002C8B4 3C07FFFD */  lui       $a3, 0xfffd
/* 7CB8 8002C8B8 34E7A800 */  ori       $a3, $a3, 0xa800
/* 7CBC 8002C8BC AFB00018 */  sw        $s0, 0x18($sp)
/* 7CC0 8002C8C0 3C10800A */  lui       $s0, %hi(D_8009BB30)
/* 7CC4 8002C8C4 2610BB30 */  addiu     $s0, $s0, %lo(D_8009BB30)
/* 7CC8 8002C8C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7CCC 8002C8CC 261109B0 */  addiu     $s1, $s0, 0x9b0
/* 7CD0 8002C8D0 0220202D */  daddu     $a0, $s1, $zero
/* 7CD4 8002C8D4 260509C8 */  addiu     $a1, $s0, 0x9c8
/* 7CD8 8002C8D8 24060001 */  addiu     $a2, $zero, 1
/* 7CDC 8002C8DC 24020140 */  addiu     $v0, $zero, 0x140
/* 7CE0 8002C8E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7CE4 8002C8E4 A60209D0 */  sh        $v0, 0x9d0($s0)
/* 7CE8 8002C8E8 24020010 */  addiu     $v0, $zero, 0x10
/* 7CEC 8002C8EC A60209D2 */  sh        $v0, 0x9d2($s0)
/* 7CF0 8002C8F0 3C028000 */  lui       $v0, %hi(D_80000318)
/* 7CF4 8002C8F4 8C420318 */  lw        $v0, %lo(D_80000318)($v0)
/* 7CF8 8002C8F8 3C03A000 */  lui       $v1, 0xa000
/* 7CFC 8002C8FC 00431025 */  or        $v0, $v0, $v1
/* 7D00 8002C900 00471021 */  addu      $v0, $v0, $a3
/* 7D04 8002C904 0C019560 */  jal       osCreateMesgQueue
/* 7D08 8002C908 AE0209CC */   sw       $v0, 0x9cc($s0)
/* 7D0C 8002C90C 0200202D */  daddu     $a0, $s0, $zero
/* 7D10 8002C910 24050002 */  addiu     $a1, $zero, 2
/* 7D14 8002C914 3C068003 */  lui       $a2, %hi(crash_monitor_thread)
/* 7D18 8002C918 24C6C81C */  addiu     $a2, $a2, %lo(crash_monitor_thread)
/* 7D1C 8002C91C 24020080 */  addiu     $v0, $zero, 0x80
/* 7D20 8002C920 0000382D */  daddu     $a3, $zero, $zero
/* 7D24 8002C924 AFB10010 */  sw        $s1, 0x10($sp)
/* 7D28 8002C928 0C019798 */  jal       osCreateThread
/* 7D2C 8002C92C AFA20014 */   sw       $v0, 0x14($sp)
/* 7D30 8002C930 0C019808 */  jal       osStartThread
/* 7D34 8002C934 0200202D */   daddu    $a0, $s0, $zero
/* 7D38 8002C938 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7D3C 8002C93C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7D40 8002C940 8FB00018 */  lw        $s0, 0x18($sp)
/* 7D44 8002C944 03E00008 */  jr        $ra
/* 7D48 8002C948 27BD0028 */   addiu    $sp, $sp, 0x28
