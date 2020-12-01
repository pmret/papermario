.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024113C_BE8D1C
/* BE8D1C 8024113C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BE8D20 80241140 AFB40040 */  sw        $s4, 0x40($sp)
/* BE8D24 80241144 0080A02D */  daddu     $s4, $a0, $zero
/* BE8D28 80241148 AFBF0048 */  sw        $ra, 0x48($sp)
/* BE8D2C 8024114C AFB50044 */  sw        $s5, 0x44($sp)
/* BE8D30 80241150 AFB3003C */  sw        $s3, 0x3c($sp)
/* BE8D34 80241154 AFB20038 */  sw        $s2, 0x38($sp)
/* BE8D38 80241158 AFB10034 */  sw        $s1, 0x34($sp)
/* BE8D3C 8024115C AFB00030 */  sw        $s0, 0x30($sp)
/* BE8D40 80241160 8E930148 */  lw        $s3, 0x148($s4)
/* BE8D44 80241164 86640008 */  lh        $a0, 8($s3)
/* BE8D48 80241168 8E90000C */  lw        $s0, 0xc($s4)
/* BE8D4C 8024116C 0C00EABB */  jal       get_npc_unsafe
/* BE8D50 80241170 00A0882D */   daddu    $s1, $a1, $zero
/* BE8D54 80241174 0280202D */  daddu     $a0, $s4, $zero
/* BE8D58 80241178 8E050000 */  lw        $a1, ($s0)
/* BE8D5C 8024117C 0C0B1EAF */  jal       get_variable
/* BE8D60 80241180 0040A82D */   daddu    $s5, $v0, $zero
/* BE8D64 80241184 AFA00010 */  sw        $zero, 0x10($sp)
/* BE8D68 80241188 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE8D6C 8024118C 8C630094 */  lw        $v1, 0x94($v1)
/* BE8D70 80241190 AFA30014 */  sw        $v1, 0x14($sp)
/* BE8D74 80241194 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE8D78 80241198 8C630080 */  lw        $v1, 0x80($v1)
/* BE8D7C 8024119C AFA30018 */  sw        $v1, 0x18($sp)
/* BE8D80 802411A0 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE8D84 802411A4 8C630088 */  lw        $v1, 0x88($v1)
/* BE8D88 802411A8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BE8D8C 802411AC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE8D90 802411B0 8C63008C */  lw        $v1, 0x8c($v1)
/* BE8D94 802411B4 27B20010 */  addiu     $s2, $sp, 0x10
/* BE8D98 802411B8 AFA30020 */  sw        $v1, 0x20($sp)
/* BE8D9C 802411BC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BE8DA0 802411C0 3C0142C8 */  lui       $at, 0x42c8
/* BE8DA4 802411C4 44810000 */  mtc1      $at, $f0
/* BE8DA8 802411C8 8C630090 */  lw        $v1, 0x90($v1)
/* BE8DAC 802411CC 0040802D */  daddu     $s0, $v0, $zero
/* BE8DB0 802411D0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BE8DB4 802411D4 A7A0002C */  sh        $zero, 0x2c($sp)
/* BE8DB8 802411D8 12200007 */  beqz      $s1, .L802411F8
/* BE8DBC 802411DC AFA30024 */   sw       $v1, 0x24($sp)
/* BE8DC0 802411E0 AE800070 */  sw        $zero, 0x70($s4)
/* BE8DC4 802411E4 8EA20000 */  lw        $v0, ($s5)
/* BE8DC8 802411E8 2403F7FF */  addiu     $v1, $zero, -0x801
/* BE8DCC 802411EC A6A0008E */  sh        $zero, 0x8e($s5)
/* BE8DD0 802411F0 00431024 */  and       $v0, $v0, $v1
/* BE8DD4 802411F4 AEA20000 */  sw        $v0, ($s5)
.L802411F8:
/* BE8DD8 802411F8 8E830070 */  lw        $v1, 0x70($s4)
/* BE8DDC 802411FC 2C620005 */  sltiu     $v0, $v1, 5
/* BE8DE0 80241200 1040001E */  beqz      $v0, .L8024127C
/* BE8DE4 80241204 00031080 */   sll      $v0, $v1, 2
/* BE8DE8 80241208 3C018024 */  lui       $at, %hi(D_802451F0)
/* BE8DEC 8024120C 00220821 */  addu      $at, $at, $v0
/* BE8DF0 80241210 8C2251F0 */  lw        $v0, %lo(D_802451F0)($at)
/* BE8DF4 80241214 00400008 */  jr        $v0
/* BE8DF8 80241218 00000000 */   nop      
/* BE8DFC 8024121C 0280202D */  daddu     $a0, $s4, $zero
/* BE8E00 80241220 0200282D */  daddu     $a1, $s0, $zero
/* BE8E04 80241224 0C090000 */  jal       func_80240000_BE7BE0
/* BE8E08 80241228 0240302D */   daddu    $a2, $s2, $zero
/* BE8E0C 8024122C 0280202D */  daddu     $a0, $s4, $zero
/* BE8E10 80241230 0200282D */  daddu     $a1, $s0, $zero
/* BE8E14 80241234 0C0903A4 */  jal       func_80240E90_BE8A70
/* BE8E18 80241238 0240302D */   daddu    $a2, $s2, $zero
/* BE8E1C 8024123C 0809049F */  j         .L8024127C
/* BE8E20 80241240 00000000 */   nop      
/* BE8E24 80241244 0280202D */  daddu     $a0, $s4, $zero
/* BE8E28 80241248 0200282D */  daddu     $a1, $s0, $zero
/* BE8E2C 8024124C 0C090100 */  jal       UnkNpcAIFunc1
/* BE8E30 80241250 0240302D */   daddu    $a2, $s2, $zero
/* BE8E34 80241254 0280202D */  daddu     $a0, $s4, $zero
/* BE8E38 80241258 0200282D */  daddu     $a1, $s0, $zero
/* BE8E3C 8024125C 0C09041A */  jal       func_80241068_BE8C48
/* BE8E40 80241260 0240302D */   daddu    $a2, $s2, $zero
/* BE8E44 80241264 0809049F */  j         .L8024127C
/* BE8E48 80241268 00000000 */   nop      
/* BE8E4C 8024126C 0280202D */  daddu     $a0, $s4, $zero
/* BE8E50 80241270 0200282D */  daddu     $a1, $s0, $zero
/* BE8E54 80241274 0C09019F */  jal       func_8024067C_BE825C
/* BE8E58 80241278 0240302D */   daddu    $a2, $s2, $zero
.L8024127C:
/* BE8E5C 8024127C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* BE8E60 80241280 4600008D */  trunc.w.s $f2, $f0
/* BE8E64 80241284 E662006C */  swc1      $f2, 0x6c($s3)
/* BE8E68 80241288 8FBF0048 */  lw        $ra, 0x48($sp)
/* BE8E6C 8024128C 8FB50044 */  lw        $s5, 0x44($sp)
/* BE8E70 80241290 8FB40040 */  lw        $s4, 0x40($sp)
/* BE8E74 80241294 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE8E78 80241298 8FB20038 */  lw        $s2, 0x38($sp)
/* BE8E7C 8024129C 8FB10034 */  lw        $s1, 0x34($sp)
/* BE8E80 802412A0 8FB00030 */  lw        $s0, 0x30($sp)
/* BE8E84 802412A4 0000102D */  daddu     $v0, $zero, $zero
/* BE8E88 802412A8 03E00008 */  jr        $ra
/* BE8E8C 802412AC 27BD0050 */   addiu    $sp, $sp, 0x50
