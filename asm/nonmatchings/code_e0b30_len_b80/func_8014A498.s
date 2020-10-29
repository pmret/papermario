.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014A498
/* E0B98 8014A498 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E0B9C 8014A49C AFBF0010 */  sw        $ra, 0x10($sp)
/* E0BA0 8014A4A0 0000282D */  daddu     $a1, $zero, $zero
/* E0BA4 8014A4A4 3C068015 */  lui       $a2, 0x8015
/* E0BA8 8014A4A8 24C6F6F0 */  addiu     $a2, $a2, -0x910
/* E0BAC 8014A4AC 24C70030 */  addiu     $a3, $a2, 0x30
/* E0BB0 8014A4B0 3C048016 */  lui       $a0, 0x8016
/* E0BB4 8014A4B4 24849AF0 */  addiu     $a0, $a0, -0x6510
.L8014A4B8:
/* E0BB8 8014A4B8 0080182D */  daddu     $v1, $a0, $zero
/* E0BBC 8014A4BC 00C0102D */  daddu     $v0, $a2, $zero
.L8014A4C0:
/* E0BC0 8014A4C0 8C480000 */  lw        $t0, ($v0)
/* E0BC4 8014A4C4 8C490004 */  lw        $t1, 4($v0)
/* E0BC8 8014A4C8 8C4A0008 */  lw        $t2, 8($v0)
/* E0BCC 8014A4CC 8C4B000C */  lw        $t3, 0xc($v0)
/* E0BD0 8014A4D0 AC680000 */  sw        $t0, ($v1)
/* E0BD4 8014A4D4 AC690004 */  sw        $t1, 4($v1)
/* E0BD8 8014A4D8 AC6A0008 */  sw        $t2, 8($v1)
/* E0BDC 8014A4DC AC6B000C */  sw        $t3, 0xc($v1)
/* E0BE0 8014A4E0 24420010 */  addiu     $v0, $v0, 0x10
/* E0BE4 8014A4E4 1447FFF6 */  bne       $v0, $a3, .L8014A4C0
/* E0BE8 8014A4E8 24630010 */   addiu    $v1, $v1, 0x10
/* E0BEC 8014A4EC 24A50001 */  addiu     $a1, $a1, 1
/* E0BF0 8014A4F0 28A20002 */  slti      $v0, $a1, 2
/* E0BF4 8014A4F4 1440FFF0 */  bnez      $v0, .L8014A4B8
/* E0BF8 8014A4F8 24840030 */   addiu    $a0, $a0, 0x30
/* E0BFC 8014A4FC 24020008 */  addiu     $v0, $zero, 8
/* E0C00 8014A500 3C018016 */  lui       $at, %hi(gMusicTargetVolume)
/* E0C04 8014A504 A4229AE2 */  sh        $v0, %lo(gMusicTargetVolume)($at)
/* E0C08 8014A508 3C018016 */  lui       $at, %hi(gMusicUnkVolume2)
/* E0C0C 8014A50C A4229AE4 */  sh        $v0, %lo(gMusicUnkVolume2)($at)
/* E0C10 8014A510 3C018016 */  lui       $at, 0x8016
/* E0C14 8014A514 A4229AE6 */  sh        $v0, -0x651a($at)
/* E0C18 8014A518 0C015869 */  jal       func_800561A4
/* E0C1C 8014A51C 24040008 */   addiu    $a0, $zero, 8
/* E0C20 8014A520 8FBF0010 */  lw        $ra, 0x10($sp)
/* E0C24 8014A524 03E00008 */  jr        $ra
/* E0C28 8014A528 27BD0018 */   addiu    $sp, $sp, 0x18
