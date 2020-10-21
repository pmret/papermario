.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242310_C5CA50
/* C5CA50 80242310 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5CA54 80242314 AFBF0010 */  sw        $ra, 0x10($sp)
/* C5CA58 80242318 10A00003 */  beqz      $a1, .L80242328
/* C5CA5C 8024231C 8C86000C */   lw       $a2, 0xc($a0)
/* C5CA60 80242320 3C018024 */  lui       $at, 0x8024
/* C5CA64 80242324 AC204A74 */  sw        $zero, 0x4a74($at)
.L80242328:
/* C5CA68 80242328 3C038024 */  lui       $v1, 0x8024
/* C5CA6C 8024232C 24634A74 */  addiu     $v1, $v1, 0x4a74
/* C5CA70 80242330 8C620000 */  lw        $v0, ($v1)
/* C5CA74 80242334 54400003 */  bnel      $v0, $zero, .L80242344
/* C5CA78 80242338 AC600000 */   sw       $zero, ($v1)
/* C5CA7C 8024233C 080908D6 */  j         .L80242358
/* C5CA80 80242340 0000102D */   daddu    $v0, $zero, $zero
.L80242344:
/* C5CA84 80242344 8CC50000 */  lw        $a1, ($a2)
/* C5CA88 80242348 3C068024 */  lui       $a2, 0x8024
/* C5CA8C 8024234C 0C0B2026 */  jal       set_variable
/* C5CA90 80242350 8CC64A78 */   lw       $a2, 0x4a78($a2)
/* C5CA94 80242354 24020002 */  addiu     $v0, $zero, 2
.L80242358:
/* C5CA98 80242358 8FBF0010 */  lw        $ra, 0x10($sp)
/* C5CA9C 8024235C 03E00008 */  jr        $ra
/* C5CAA0 80242360 27BD0018 */   addiu    $sp, $sp, 0x18
