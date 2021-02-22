.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D38EC
/* F829C 802D38EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F82A0 802D38F0 AFB20018 */  sw        $s2, 0x18($sp)
/* F82A4 802D38F4 0080902D */  daddu     $s2, $a0, $zero
/* F82A8 802D38F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* F82AC 802D38FC AFB10014 */  sw        $s1, 0x14($sp)
/* F82B0 802D3900 AFB00010 */  sw        $s0, 0x10($sp)
/* F82B4 802D3904 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F82B8 802D3908 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F82BC 802D390C 8E50000C */  lw        $s0, 0xc($s2)
/* F82C0 802D3910 8E050000 */  lw        $a1, ($s0)
/* F82C4 802D3914 0C0B1EAF */  jal       get_variable
/* F82C8 802D3918 26100004 */   addiu    $s0, $s0, 4
/* F82CC 802D391C 8E050000 */  lw        $a1, ($s0)
/* F82D0 802D3920 26100004 */  addiu     $s0, $s0, 4
/* F82D4 802D3924 0240202D */  daddu     $a0, $s2, $zero
/* F82D8 802D3928 0C0B210B */  jal       get_float_variable
/* F82DC 802D392C 0040882D */   daddu    $s1, $v0, $zero
/* F82E0 802D3930 8E050000 */  lw        $a1, ($s0)
/* F82E4 802D3934 26100004 */  addiu     $s0, $s0, 4
/* F82E8 802D3938 0240202D */  daddu     $a0, $s2, $zero
/* F82EC 802D393C 0C0B210B */  jal       get_float_variable
/* F82F0 802D3940 46000586 */   mov.s    $f22, $f0
/* F82F4 802D3944 0240202D */  daddu     $a0, $s2, $zero
/* F82F8 802D3948 8E050000 */  lw        $a1, ($s0)
/* F82FC 802D394C 0C0B210B */  jal       get_float_variable
/* F8300 802D3950 46000506 */   mov.s    $f20, $f0
/* F8304 802D3954 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F8308 802D3958 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F830C 802D395C 00118880 */  sll       $s1, $s1, 2
/* F8310 802D3960 02228821 */  addu      $s1, $s1, $v0
/* F8314 802D3964 8E230000 */  lw        $v1, ($s1)
/* F8318 802D3968 E476001C */  swc1      $f22, 0x1c($v1)
/* F831C 802D396C E4740020 */  swc1      $f20, 0x20($v1)
/* F8320 802D3970 E4600024 */  swc1      $f0, 0x24($v1)
/* F8324 802D3974 8FBF001C */  lw        $ra, 0x1c($sp)
/* F8328 802D3978 8FB20018 */  lw        $s2, 0x18($sp)
/* F832C 802D397C 8FB10014 */  lw        $s1, 0x14($sp)
/* F8330 802D3980 8FB00010 */  lw        $s0, 0x10($sp)
/* F8334 802D3984 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F8338 802D3988 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F833C 802D398C 24020002 */  addiu     $v0, $zero, 2
/* F8340 802D3990 03E00008 */  jr        $ra
/* F8344 802D3994 27BD0030 */   addiu    $sp, $sp, 0x30
