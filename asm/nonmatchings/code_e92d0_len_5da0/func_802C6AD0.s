.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C6AD0
/* EB480 802C6AD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB484 802C6AD4 AFB00010 */  sw        $s0, 0x10($sp)
/* EB488 802C6AD8 0080802D */  daddu     $s0, $a0, $zero
/* EB48C 802C6ADC AFBF0014 */  sw        $ra, 0x14($sp)
/* EB490 802C6AE0 8E020014 */  lw        $v0, 0x14($s0)
/* EB494 802C6AE4 1440000F */  bnez      $v0, .L802C6B24
/* EB498 802C6AE8 00000000 */   nop      
/* EB49C 802C6AEC 8E040010 */  lw        $a0, 0x10($s0)
/* EB4A0 802C6AF0 8E050018 */  lw        $a1, 0x18($s0)
/* EB4A4 802C6AF4 0C0B0CF8 */  jal       start_script
/* EB4A8 802C6AF8 24060020 */   addiu    $a2, $zero, 0x20
/* EB4AC 802C6AFC AE020014 */  sw        $v0, 0x14($s0)
/* EB4B0 802C6B00 8C430144 */  lw        $v1, 0x144($v0)
/* EB4B4 802C6B04 8E04001C */  lw        $a0, 0x1c($s0)
/* EB4B8 802C6B08 AE030034 */  sw        $v1, 0x34($s0)
/* EB4BC 802C6B0C AC440084 */  sw        $a0, 0x84($v0)
/* EB4C0 802C6B10 8E030020 */  lw        $v1, 0x20($s0)
/* EB4C4 802C6B14 AC430088 */  sw        $v1, 0x88($v0)
/* EB4C8 802C6B18 8E030024 */  lw        $v1, 0x24($s0)
/* EB4CC 802C6B1C AC50014C */  sw        $s0, 0x14c($v0)
/* EB4D0 802C6B20 AC43008C */  sw        $v1, 0x8c($v0)
.L802C6B24:
/* EB4D4 802C6B24 0C0B1059 */  jal       does_script_exist
/* EB4D8 802C6B28 8E040034 */   lw       $a0, 0x34($s0)
/* EB4DC 802C6B2C 14400005 */  bnez      $v0, .L802C6B44
/* EB4E0 802C6B30 2403FFFD */   addiu    $v1, $zero, -3
/* EB4E4 802C6B34 8E020000 */  lw        $v0, ($s0)
/* EB4E8 802C6B38 AE000014 */  sw        $zero, 0x14($s0)
/* EB4EC 802C6B3C 00431024 */  and       $v0, $v0, $v1
/* EB4F0 802C6B40 AE020000 */  sw        $v0, ($s0)
.L802C6B44:
/* EB4F4 802C6B44 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB4F8 802C6B48 8FB00010 */  lw        $s0, 0x10($sp)
/* EB4FC 802C6B4C 03E00008 */  jr        $ra
/* EB500 802C6B50 27BD0018 */   addiu    $sp, $sp, 0x18
