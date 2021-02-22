.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401EC_DC45BC
/* DC45BC 802401EC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DC45C0 802401F0 AFB10014 */  sw        $s1, 0x14($sp)
/* DC45C4 802401F4 0080882D */  daddu     $s1, $a0, $zero
/* DC45C8 802401F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DC45CC 802401FC AFB00010 */  sw        $s0, 0x10($sp)
/* DC45D0 80240200 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DC45D4 80240204 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DC45D8 80240208 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DC45DC 8024020C 8E30000C */  lw        $s0, 0xc($s1)
/* DC45E0 80240210 8E050000 */  lw        $a1, ($s0)
/* DC45E4 80240214 0C0B210B */  jal       get_float_variable
/* DC45E8 80240218 26100004 */   addiu    $s0, $s0, 4
/* DC45EC 8024021C 8E050000 */  lw        $a1, ($s0)
/* DC45F0 80240220 26100004 */  addiu     $s0, $s0, 4
/* DC45F4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* DC45F8 80240228 0C0B210B */  jal       get_float_variable
/* DC45FC 8024022C 46000606 */   mov.s    $f24, $f0
/* DC4600 80240230 8E050000 */  lw        $a1, ($s0)
/* DC4604 80240234 26100004 */  addiu     $s0, $s0, 4
/* DC4608 80240238 0220202D */  daddu     $a0, $s1, $zero
/* DC460C 8024023C 0C0B210B */  jal       get_float_variable
/* DC4610 80240240 46000586 */   mov.s    $f22, $f0
/* DC4614 80240244 0220202D */  daddu     $a0, $s1, $zero
/* DC4618 80240248 8E050000 */  lw        $a1, ($s0)
/* DC461C 8024024C 0C0B210B */  jal       get_float_variable
/* DC4620 80240250 46000506 */   mov.s    $f20, $f0
/* DC4624 80240254 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DC4628 80240258 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DC462C 8024025C E4580028 */  swc1      $f24, 0x28($v0)
/* DC4630 80240260 E456002C */  swc1      $f22, 0x2c($v0)
/* DC4634 80240264 E4540030 */  swc1      $f20, 0x30($v0)
/* DC4638 80240268 E4400080 */  swc1      $f0, 0x80($v0)
/* DC463C 8024026C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DC4640 80240270 8FB10014 */  lw        $s1, 0x14($sp)
/* DC4644 80240274 8FB00010 */  lw        $s0, 0x10($sp)
/* DC4648 80240278 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DC464C 8024027C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DC4650 80240280 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DC4654 80240284 24020002 */  addiu     $v0, $zero, 2
/* DC4658 80240288 03E00008 */  jr        $ra
/* DC465C 8024028C 27BD0038 */   addiu    $sp, $sp, 0x38
