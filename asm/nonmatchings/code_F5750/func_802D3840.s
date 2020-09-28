.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3840
/* F81F0 802D3840 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F81F4 802D3844 AFB20018 */  sw        $s2, 0x18($sp)
/* F81F8 802D3848 0080902D */  daddu     $s2, $a0, $zero
/* F81FC 802D384C AFBF001C */  sw        $ra, 0x1c($sp)
/* F8200 802D3850 AFB10014 */  sw        $s1, 0x14($sp)
/* F8204 802D3854 AFB00010 */  sw        $s0, 0x10($sp)
/* F8208 802D3858 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F820C 802D385C F7B40020 */  sdc1      $f20, 0x20($sp)
/* F8210 802D3860 8E50000C */  lw        $s0, 0xc($s2)
/* F8214 802D3864 8E050000 */  lw        $a1, ($s0)
/* F8218 802D3868 0C0B1EAF */  jal       get_variable
/* F821C 802D386C 26100004 */   addiu    $s0, $s0, 4
/* F8220 802D3870 8E050000 */  lw        $a1, ($s0)
/* F8224 802D3874 26100004 */  addiu     $s0, $s0, 4
/* F8228 802D3878 0240202D */  daddu     $a0, $s2, $zero
/* F822C 802D387C 0C0B210B */  jal       get_float_variable
/* F8230 802D3880 0040882D */   daddu    $s1, $v0, $zero
/* F8234 802D3884 8E050000 */  lw        $a1, ($s0)
/* F8238 802D3888 26100004 */  addiu     $s0, $s0, 4
/* F823C 802D388C 0240202D */  daddu     $a0, $s2, $zero
/* F8240 802D3890 0C0B210B */  jal       get_float_variable
/* F8244 802D3894 46000586 */   mov.s    $f22, $f0
/* F8248 802D3898 0240202D */  daddu     $a0, $s2, $zero
/* F824C 802D389C 8E050000 */  lw        $a1, ($s0)
/* F8250 802D38A0 0C0B210B */  jal       get_float_variable
/* F8254 802D38A4 46000506 */   mov.s    $f20, $f0
/* F8258 802D38A8 3C02802E */  lui       $v0, 0x802e
/* F825C 802D38AC 8C42B7C0 */  lw        $v0, -0x4840($v0)
/* F8260 802D38B0 00118880 */  sll       $s1, $s1, 2
/* F8264 802D38B4 02228821 */  addu      $s1, $s1, $v0
/* F8268 802D38B8 8E230000 */  lw        $v1, ($s1)
/* F826C 802D38BC E4760010 */  swc1      $f22, 0x10($v1)
/* F8270 802D38C0 E4740014 */  swc1      $f20, 0x14($v1)
/* F8274 802D38C4 E4600018 */  swc1      $f0, 0x18($v1)
/* F8278 802D38C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* F827C 802D38CC 8FB20018 */  lw        $s2, 0x18($sp)
/* F8280 802D38D0 8FB10014 */  lw        $s1, 0x14($sp)
/* F8284 802D38D4 8FB00010 */  lw        $s0, 0x10($sp)
/* F8288 802D38D8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F828C 802D38DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* F8290 802D38E0 24020002 */  addiu     $v0, $zero, 2
/* F8294 802D38E4 03E00008 */  jr        $ra
/* F8298 802D38E8 27BD0030 */   addiu    $sp, $sp, 0x30
