.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel crash_monitor_thread
/* 007C1C 8002C81C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 007C20 8002C820 2404000A */  addiu $a0, $zero, 0xa
/* 007C24 8002C824 AFB00018 */  sw    $s0, 0x18($sp)
/* 007C28 8002C828 3C10800A */  lui   $s0, 0x800a
/* 007C2C 8002C82C 2610C4E0 */  addiu $s0, $s0, -0x3b20
/* 007C30 8002C830 0200282D */  daddu $a1, $s0, $zero
/* 007C34 8002C834 AFBF001C */  sw    $ra, 0x1c($sp)
/* 007C38 8002C838 0C019654 */  jal   osSetEventMesg
/* 007C3C 8002C83C 24060001 */   addiu $a2, $zero, 1
/* 007C40 8002C840 2404000C */  addiu $a0, $zero, 0xc
/* 007C44 8002C844 0200282D */  daddu $a1, $s0, $zero
/* 007C48 8002C848 0C019654 */  jal   osSetEventMesg
/* 007C4C 8002C84C 24060002 */   addiu $a2, $zero, 2
.L8002C850:
/* 007C50 8002C850 3C04800A */  lui   $a0, 0x800a
/* 007C54 8002C854 2484C4E0 */  addiu $a0, $a0, -0x3b20
/* 007C58 8002C858 27A50010 */  addiu $a1, $sp, 0x10
/* 007C5C 8002C85C 0C0195BC */  jal   osRecvMesg
/* 007C60 8002C860 24060001 */   addiu $a2, $zero, 1
/* 007C64 8002C864 0C00B1EC */  jal   func_8002C7B0
/* 007C68 8002C868 00000000 */   nop   
/* 007C6C 8002C86C 0040802D */  daddu $s0, $v0, $zero
/* 007C70 8002C870 1200FFF7 */  beqz  $s0, .L8002C850
/* 007C74 8002C874 00000000 */   nop   
/* 007C78 8002C878 0C019850 */  jal   osStopThread
/* 007C7C 8002C87C 0200202D */   daddu $a0, $s0, $zero
/* 007C80 8002C880 0C00B0EC */  jal   crash_show_handler
/* 007C84 8002C884 0200202D */   daddu $a0, $s0, $zero
.L8002C888:
/* 007C88 8002C888 0800B222 */  j     .L8002C888
/* 007C8C 8002C88C 00000000 */   nop   

