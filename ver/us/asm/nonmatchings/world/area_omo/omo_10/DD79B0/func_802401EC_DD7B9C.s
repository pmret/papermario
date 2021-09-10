.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401EC_DD7B9C
/* DD7B9C 802401EC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DD7BA0 802401F0 AFB10014 */  sw        $s1, 0x14($sp)
/* DD7BA4 802401F4 0080882D */  daddu     $s1, $a0, $zero
/* DD7BA8 802401F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* DD7BAC 802401FC AFB00010 */  sw        $s0, 0x10($sp)
/* DD7BB0 80240200 F7B80030 */  sdc1      $f24, 0x30($sp)
/* DD7BB4 80240204 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DD7BB8 80240208 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DD7BBC 8024020C 8E30000C */  lw        $s0, 0xc($s1)
/* DD7BC0 80240210 8E050000 */  lw        $a1, ($s0)
/* DD7BC4 80240214 0C0B210B */  jal       evt_get_float_variable
/* DD7BC8 80240218 26100004 */   addiu    $s0, $s0, 4
/* DD7BCC 8024021C 8E050000 */  lw        $a1, ($s0)
/* DD7BD0 80240220 26100004 */  addiu     $s0, $s0, 4
/* DD7BD4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* DD7BD8 80240228 0C0B210B */  jal       evt_get_float_variable
/* DD7BDC 8024022C 46000606 */   mov.s    $f24, $f0
/* DD7BE0 80240230 8E050000 */  lw        $a1, ($s0)
/* DD7BE4 80240234 26100004 */  addiu     $s0, $s0, 4
/* DD7BE8 80240238 0220202D */  daddu     $a0, $s1, $zero
/* DD7BEC 8024023C 0C0B210B */  jal       evt_get_float_variable
/* DD7BF0 80240240 46000586 */   mov.s    $f22, $f0
/* DD7BF4 80240244 0220202D */  daddu     $a0, $s1, $zero
/* DD7BF8 80240248 8E050000 */  lw        $a1, ($s0)
/* DD7BFC 8024024C 0C0B210B */  jal       evt_get_float_variable
/* DD7C00 80240250 46000506 */   mov.s    $f20, $f0
/* DD7C04 80240254 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DD7C08 80240258 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* DD7C0C 8024025C E4580028 */  swc1      $f24, 0x28($v0)
/* DD7C10 80240260 E456002C */  swc1      $f22, 0x2c($v0)
/* DD7C14 80240264 E4540030 */  swc1      $f20, 0x30($v0)
/* DD7C18 80240268 E4400080 */  swc1      $f0, 0x80($v0)
/* DD7C1C 8024026C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DD7C20 80240270 8FB10014 */  lw        $s1, 0x14($sp)
/* DD7C24 80240274 8FB00010 */  lw        $s0, 0x10($sp)
/* DD7C28 80240278 D7B80030 */  ldc1      $f24, 0x30($sp)
/* DD7C2C 8024027C D7B60028 */  ldc1      $f22, 0x28($sp)
/* DD7C30 80240280 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DD7C34 80240284 24020002 */  addiu     $v0, $zero, 2
/* DD7C38 80240288 03E00008 */  jr        $ra
/* DD7C3C 8024028C 27BD0038 */   addiu    $sp, $sp, 0x38
