.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024020C
/* DA544C 8024020C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DA5450 80240210 AFB10014 */  sw        $s1, 0x14($sp)
/* DA5454 80240214 0080882D */  daddu     $s1, $a0, $zero
/* DA5458 80240218 AFBF0018 */  sw        $ra, 0x18($sp)
/* DA545C 8024021C AFB00010 */  sw        $s0, 0x10($sp)
/* DA5460 80240220 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DA5464 80240224 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DA5468 80240228 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DA546C 8024022C 8E30000C */  lw        $s0, 0xc($s1)
/* DA5470 80240230 8E050000 */  lw        $a1, ($s0)
/* DA5474 80240234 0C0B210B */  jal       get_float_variable
/* DA5478 80240238 26100004 */   addiu    $s0, $s0, 4
/* DA547C 8024023C 8E050000 */  lw        $a1, ($s0)
/* DA5480 80240240 26100004 */  addiu     $s0, $s0, 4
/* DA5484 80240244 0220202D */  daddu     $a0, $s1, $zero
/* DA5488 80240248 0C0B210B */  jal       get_float_variable
/* DA548C 8024024C 46000606 */   mov.s    $f24, $f0
/* DA5490 80240250 8E050000 */  lw        $a1, ($s0)
/* DA5494 80240254 26100004 */  addiu     $s0, $s0, 4
/* DA5498 80240258 0220202D */  daddu     $a0, $s1, $zero
/* DA549C 8024025C 0C0B210B */  jal       get_float_variable
/* DA54A0 80240260 46000586 */   mov.s    $f22, $f0
/* DA54A4 80240264 0220202D */  daddu     $a0, $s1, $zero
/* DA54A8 80240268 8E050000 */  lw        $a1, ($s0)
/* DA54AC 8024026C 0C0B210B */  jal       get_float_variable
/* DA54B0 80240270 46000506 */   mov.s    $f20, $f0
/* DA54B4 80240274 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DA54B8 80240278 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DA54BC 8024027C E4580028 */  swc1      $f24, 0x28($v0)
/* DA54C0 80240280 E456002C */  swc1      $f22, 0x2c($v0)
/* DA54C4 80240284 E4540030 */  swc1      $f20, 0x30($v0)
/* DA54C8 80240288 E4400080 */  swc1      $f0, 0x80($v0)
/* DA54CC 8024028C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DA54D0 80240290 8FB10014 */  lw        $s1, 0x14($sp)
/* DA54D4 80240294 8FB00010 */  lw        $s0, 0x10($sp)
/* DA54D8 80240298 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DA54DC 8024029C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DA54E0 802402A0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DA54E4 802402A4 24020002 */  addiu     $v0, $zero, 2
/* DA54E8 802402A8 03E00008 */  jr        $ra
/* DA54EC 802402AC 27BD0038 */   addiu    $sp, $sp, 0x38
