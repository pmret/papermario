.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401EC_DB7AFC
/* DB7AFC 802401EC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DB7B00 802401F0 AFB10014 */  sw        $s1, 0x14($sp)
/* DB7B04 802401F4 0080882D */  daddu     $s1, $a0, $zero
/* DB7B08 802401F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB7B0C 802401FC AFB00010 */  sw        $s0, 0x10($sp)
/* DB7B10 80240200 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DB7B14 80240204 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DB7B18 80240208 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DB7B1C 8024020C 8E30000C */  lw        $s0, 0xc($s1)
/* DB7B20 80240210 8E050000 */  lw        $a1, ($s0)
/* DB7B24 80240214 0C0B210B */  jal       get_float_variable
/* DB7B28 80240218 26100004 */   addiu    $s0, $s0, 4
/* DB7B2C 8024021C 8E050000 */  lw        $a1, ($s0)
/* DB7B30 80240220 26100004 */  addiu     $s0, $s0, 4
/* DB7B34 80240224 0220202D */  daddu     $a0, $s1, $zero
/* DB7B38 80240228 0C0B210B */  jal       get_float_variable
/* DB7B3C 8024022C 46000606 */   mov.s    $f24, $f0
/* DB7B40 80240230 8E050000 */  lw        $a1, ($s0)
/* DB7B44 80240234 26100004 */  addiu     $s0, $s0, 4
/* DB7B48 80240238 0220202D */  daddu     $a0, $s1, $zero
/* DB7B4C 8024023C 0C0B210B */  jal       get_float_variable
/* DB7B50 80240240 46000586 */   mov.s    $f22, $f0
/* DB7B54 80240244 0220202D */  daddu     $a0, $s1, $zero
/* DB7B58 80240248 8E050000 */  lw        $a1, ($s0)
/* DB7B5C 8024024C 0C0B210B */  jal       get_float_variable
/* DB7B60 80240250 46000506 */   mov.s    $f20, $f0
/* DB7B64 80240254 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DB7B68 80240258 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DB7B6C 8024025C E4580028 */  swc1      $f24, 0x28($v0)
/* DB7B70 80240260 E456002C */  swc1      $f22, 0x2c($v0)
/* DB7B74 80240264 E4540030 */  swc1      $f20, 0x30($v0)
/* DB7B78 80240268 E4400080 */  swc1      $f0, 0x80($v0)
/* DB7B7C 8024026C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB7B80 80240270 8FB10014 */  lw        $s1, 0x14($sp)
/* DB7B84 80240274 8FB00010 */  lw        $s0, 0x10($sp)
/* DB7B88 80240278 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DB7B8C 8024027C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DB7B90 80240280 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DB7B94 80240284 24020002 */  addiu     $v0, $zero, 2
/* DB7B98 80240288 03E00008 */  jr        $ra
/* DB7B9C 8024028C 27BD0038 */   addiu    $sp, $sp, 0x38
