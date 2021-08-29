.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401EC_DEC0BC
/* DEC0BC 802401EC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DEC0C0 802401F0 AFB10014 */  sw        $s1, 0x14($sp)
/* DEC0C4 802401F4 0080882D */  daddu     $s1, $a0, $zero
/* DEC0C8 802401F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DEC0CC 802401FC AFB00010 */  sw        $s0, 0x10($sp)
/* DEC0D0 80240200 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DEC0D4 80240204 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DEC0D8 80240208 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEC0DC 8024020C 8E30000C */  lw        $s0, 0xc($s1)
/* DEC0E0 80240210 8E050000 */  lw        $a1, ($s0)
/* DEC0E4 80240214 0C0B210B */  jal       evt_get_float_variable
/* DEC0E8 80240218 26100004 */   addiu    $s0, $s0, 4
/* DEC0EC 8024021C 8E050000 */  lw        $a1, ($s0)
/* DEC0F0 80240220 26100004 */  addiu     $s0, $s0, 4
/* DEC0F4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* DEC0F8 80240228 0C0B210B */  jal       evt_get_float_variable
/* DEC0FC 8024022C 46000606 */   mov.s    $f24, $f0
/* DEC100 80240230 8E050000 */  lw        $a1, ($s0)
/* DEC104 80240234 26100004 */  addiu     $s0, $s0, 4
/* DEC108 80240238 0220202D */  daddu     $a0, $s1, $zero
/* DEC10C 8024023C 0C0B210B */  jal       evt_get_float_variable
/* DEC110 80240240 46000586 */   mov.s    $f22, $f0
/* DEC114 80240244 0220202D */  daddu     $a0, $s1, $zero
/* DEC118 80240248 8E050000 */  lw        $a1, ($s0)
/* DEC11C 8024024C 0C0B210B */  jal       evt_get_float_variable
/* DEC120 80240250 46000506 */   mov.s    $f20, $f0
/* DEC124 80240254 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DEC128 80240258 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DEC12C 8024025C E4580028 */  swc1      $f24, 0x28($v0)
/* DEC130 80240260 E456002C */  swc1      $f22, 0x2c($v0)
/* DEC134 80240264 E4540030 */  swc1      $f20, 0x30($v0)
/* DEC138 80240268 E4400080 */  swc1      $f0, 0x80($v0)
/* DEC13C 8024026C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEC140 80240270 8FB10014 */  lw        $s1, 0x14($sp)
/* DEC144 80240274 8FB00010 */  lw        $s0, 0x10($sp)
/* DEC148 80240278 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DEC14C 8024027C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DEC150 80240280 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEC154 80240284 24020002 */  addiu     $v0, $zero, 2
/* DEC158 80240288 03E00008 */  jr        $ra
/* DEC15C 8024028C 27BD0038 */   addiu    $sp, $sp, 0x38
