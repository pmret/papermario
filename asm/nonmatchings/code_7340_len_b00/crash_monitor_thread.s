.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel crash_monitor_thread
/* 7C1C 8002C81C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7C20 8002C820 2404000A */  addiu     $a0, $zero, 0xa
/* 7C24 8002C824 AFB00018 */  sw        $s0, 0x18($sp)
/* 7C28 8002C828 3C10800A */  lui       $s0, 0x800a
/* 7C2C 8002C82C 2610C4E0 */  addiu     $s0, $s0, -0x3b20
/* 7C30 8002C830 0200282D */  daddu     $a1, $s0, $zero
/* 7C34 8002C834 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7C38 8002C838 0C019654 */  jal       osSetEventMesg
/* 7C3C 8002C83C 24060001 */   addiu    $a2, $zero, 1
/* 7C40 8002C840 2404000C */  addiu     $a0, $zero, 0xc
/* 7C44 8002C844 0200282D */  daddu     $a1, $s0, $zero
/* 7C48 8002C848 0C019654 */  jal       osSetEventMesg
/* 7C4C 8002C84C 24060002 */   addiu    $a2, $zero, 2
.L8002C850:
/* 7C50 8002C850 3C04800A */  lui       $a0, 0x800a
/* 7C54 8002C854 2484C4E0 */  addiu     $a0, $a0, -0x3b20
/* 7C58 8002C858 27A50010 */  addiu     $a1, $sp, 0x10
/* 7C5C 8002C85C 0C0195BC */  jal       osRecvMesg
/* 7C60 8002C860 24060001 */   addiu    $a2, $zero, 1
/* 7C64 8002C864 0C00B1EC */  jal       func_8002C7B0
/* 7C68 8002C868 00000000 */   nop      
/* 7C6C 8002C86C 0040802D */  daddu     $s0, $v0, $zero
/* 7C70 8002C870 1200FFF7 */  beqz      $s0, .L8002C850
/* 7C74 8002C874 00000000 */   nop      
/* 7C78 8002C878 0C019850 */  jal       osStopThread
/* 7C7C 8002C87C 0200202D */   daddu    $a0, $s0, $zero
/* 7C80 8002C880 0C00B0EC */  jal       crash_show_handler
/* 7C84 8002C884 0200202D */   daddu    $a0, $s0, $zero
.L8002C888:
/* 7C88 8002C888 0800B222 */  j         .L8002C888
/* 7C8C 8002C88C 00000000 */   nop      
