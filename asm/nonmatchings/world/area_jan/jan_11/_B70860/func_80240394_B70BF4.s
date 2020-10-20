.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_B70BF4
/* B70BF4 80240394 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B70BF8 80240398 AFB00018 */  sw        $s0, 0x18($sp)
/* B70BFC 8024039C 0080802D */  daddu     $s0, $a0, $zero
/* B70C00 802403A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* B70C04 802403A4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B70C08 802403A8 8E02000C */  lw        $v0, 0xc($s0)
/* B70C0C 802403AC 0C0B210B */  jal       get_float_variable
/* B70C10 802403B0 8C450000 */   lw       $a1, ($v0)
/* B70C14 802403B4 27A40010 */  addiu     $a0, $sp, 0x10
/* B70C18 802403B8 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* B70C1C 802403BC 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* B70C20 802403C0 44060000 */  mfc1      $a2, $f0
/* B70C24 802403C4 C4400028 */  lwc1      $f0, 0x28($v0)
/* B70C28 802403C8 C4420030 */  lwc1      $f2, 0x30($v0)
/* B70C2C 802403CC E7A00010 */  swc1      $f0, 0x10($sp)
/* B70C30 802403D0 E7A20014 */  swc1      $f2, 0x14($sp)
/* B70C34 802403D4 8C470080 */  lw        $a3, 0x80($v0)
/* B70C38 802403D8 C454002C */  lwc1      $f20, 0x2c($v0)
/* B70C3C 802403DC 0C00A7E7 */  jal       add_vec2D_polar
/* B70C40 802403E0 27A50014 */   addiu    $a1, $sp, 0x14
/* B70C44 802403E4 0200202D */  daddu     $a0, $s0, $zero
/* B70C48 802403E8 3C05FE36 */  lui       $a1, 0xfe36
/* B70C4C 802403EC 8FA60010 */  lw        $a2, 0x10($sp)
/* B70C50 802403F0 0C0B2190 */  jal       set_float_variable
/* B70C54 802403F4 34A53C80 */   ori      $a1, $a1, 0x3c80
/* B70C58 802403F8 0200202D */  daddu     $a0, $s0, $zero
/* B70C5C 802403FC 3C05FE36 */  lui       $a1, 0xfe36
/* B70C60 80240400 4406A000 */  mfc1      $a2, $f20
/* B70C64 80240404 0C0B2190 */  jal       set_float_variable
/* B70C68 80240408 34A53C81 */   ori      $a1, $a1, 0x3c81
/* B70C6C 8024040C 0200202D */  daddu     $a0, $s0, $zero
/* B70C70 80240410 3C05FE36 */  lui       $a1, 0xfe36
/* B70C74 80240414 8FA60014 */  lw        $a2, 0x14($sp)
/* B70C78 80240418 0C0B2190 */  jal       set_float_variable
/* B70C7C 8024041C 34A53C82 */   ori      $a1, $a1, 0x3c82
/* B70C80 80240420 8FBF001C */  lw        $ra, 0x1c($sp)
/* B70C84 80240424 8FB00018 */  lw        $s0, 0x18($sp)
/* B70C88 80240428 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B70C8C 8024042C 24020002 */  addiu     $v0, $zero, 2
/* B70C90 80240430 03E00008 */  jr        $ra
/* B70C94 80240434 27BD0028 */   addiu    $sp, $sp, 0x28
