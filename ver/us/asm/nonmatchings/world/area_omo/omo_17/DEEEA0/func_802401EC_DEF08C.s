.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401EC_DEF08C
/* DEF08C 802401EC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DEF090 802401F0 AFB10014 */  sw        $s1, 0x14($sp)
/* DEF094 802401F4 0080882D */  daddu     $s1, $a0, $zero
/* DEF098 802401F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DEF09C 802401FC AFB00010 */  sw        $s0, 0x10($sp)
/* DEF0A0 80240200 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DEF0A4 80240204 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DEF0A8 80240208 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DEF0AC 8024020C 8E30000C */  lw        $s0, 0xc($s1)
/* DEF0B0 80240210 8E050000 */  lw        $a1, ($s0)
/* DEF0B4 80240214 0C0B210B */  jal       evt_get_float_variable
/* DEF0B8 80240218 26100004 */   addiu    $s0, $s0, 4
/* DEF0BC 8024021C 8E050000 */  lw        $a1, ($s0)
/* DEF0C0 80240220 26100004 */  addiu     $s0, $s0, 4
/* DEF0C4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* DEF0C8 80240228 0C0B210B */  jal       evt_get_float_variable
/* DEF0CC 8024022C 46000606 */   mov.s    $f24, $f0
/* DEF0D0 80240230 8E050000 */  lw        $a1, ($s0)
/* DEF0D4 80240234 26100004 */  addiu     $s0, $s0, 4
/* DEF0D8 80240238 0220202D */  daddu     $a0, $s1, $zero
/* DEF0DC 8024023C 0C0B210B */  jal       evt_get_float_variable
/* DEF0E0 80240240 46000586 */   mov.s    $f22, $f0
/* DEF0E4 80240244 0220202D */  daddu     $a0, $s1, $zero
/* DEF0E8 80240248 8E050000 */  lw        $a1, ($s0)
/* DEF0EC 8024024C 0C0B210B */  jal       evt_get_float_variable
/* DEF0F0 80240250 46000506 */   mov.s    $f20, $f0
/* DEF0F4 80240254 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DEF0F8 80240258 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DEF0FC 8024025C E4580028 */  swc1      $f24, 0x28($v0)
/* DEF100 80240260 E456002C */  swc1      $f22, 0x2c($v0)
/* DEF104 80240264 E4540030 */  swc1      $f20, 0x30($v0)
/* DEF108 80240268 E4400080 */  swc1      $f0, 0x80($v0)
/* DEF10C 8024026C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DEF110 80240270 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF114 80240274 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF118 80240278 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DEF11C 8024027C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DEF120 80240280 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DEF124 80240284 24020002 */  addiu     $v0, $zero, 2
/* DEF128 80240288 03E00008 */  jr        $ra
/* DEF12C 8024028C 27BD0038 */   addiu    $sp, $sp, 0x38
