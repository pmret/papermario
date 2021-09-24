.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00921B4
/* 391EE4 E00921B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 391EE8 E00921B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 391EEC E00921BC 8C85000C */  lw        $a1, 0xc($a0)
/* 391EF0 E00921C0 8CA20014 */  lw        $v0, 0x14($a1)
/* 391EF4 E00921C4 2442FFFF */  addiu     $v0, $v0, -1
/* 391EF8 E00921C8 ACA20014 */  sw        $v0, 0x14($a1)
/* 391EFC E00921CC 8CA20018 */  lw        $v0, 0x18($a1)
/* 391F00 E00921D0 8CA30014 */  lw        $v1, 0x14($a1)
/* 391F04 E00921D4 24420001 */  addiu     $v0, $v0, 1
/* 391F08 E00921D8 04610005 */  bgez      $v1, .LE00921F0
/* 391F0C E00921DC ACA20018 */   sw       $v0, 0x18($a1)
/* 391F10 E00921E0 0C080128 */  jal       shim_remove_effect
/* 391F14 E00921E4 00000000 */   nop
/* 391F18 E00921E8 08024893 */  j         .LE009224C
/* 391F1C E00921EC 00000000 */   nop
.LE00921F0:
/* 391F20 E00921F0 8C820008 */  lw        $v0, 8($a0)
/* 391F24 E00921F4 24060001 */  addiu     $a2, $zero, 1
/* 391F28 E00921F8 00C2102A */  slt       $v0, $a2, $v0
/* 391F2C E00921FC 10400013 */  beqz      $v0, .LE009224C
/* 391F30 E0092200 24A50024 */   addiu    $a1, $a1, 0x24
/* 391F34 E0092204 2407FFFF */  addiu     $a3, $zero, -1
/* 391F38 E0092208 24A30020 */  addiu     $v1, $a1, 0x20
.LE009220C:
/* 391F3C E009220C 8C620000 */  lw        $v0, ($v1)
/* 391F40 E0092210 18400003 */  blez      $v0, .LE0092220
/* 391F44 E0092214 2442FFFF */   addiu    $v0, $v0, -1
/* 391F48 E0092218 1C400007 */  bgtz      $v0, .LE0092238
/* 391F4C E009221C AC620000 */   sw       $v0, ($v1)
.LE0092220:
/* 391F50 E0092220 8C62FFE4 */  lw        $v0, -0x1c($v1)
/* 391F54 E0092224 24420001 */  addiu     $v0, $v0, 1
/* 391F58 E0092228 AC62FFE4 */  sw        $v0, -0x1c($v1)
/* 391F5C E009222C 2842000A */  slti      $v0, $v0, 0xa
/* 391F60 E0092230 50400001 */  beql      $v0, $zero, .LE0092238
/* 391F64 E0092234 AC670000 */   sw       $a3, ($v1)
.LE0092238:
/* 391F68 E0092238 24C60001 */  addiu     $a2, $a2, 1
/* 391F6C E009223C 8C820008 */  lw        $v0, 8($a0)
/* 391F70 E0092240 00C2102A */  slt       $v0, $a2, $v0
/* 391F74 E0092244 1440FFF1 */  bnez      $v0, .LE009220C
/* 391F78 E0092248 24630024 */   addiu    $v1, $v1, 0x24
.LE009224C:
/* 391F7C E009224C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 391F80 E0092250 03E00008 */  jr        $ra
/* 391F84 E0092254 27BD0018 */   addiu    $sp, $sp, 0x18
