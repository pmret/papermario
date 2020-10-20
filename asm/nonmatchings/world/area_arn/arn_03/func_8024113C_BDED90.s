.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024113C_BDFECC
/* BDFECC 8024113C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BDFED0 80241140 AFB40040 */  sw        $s4, 0x40($sp)
/* BDFED4 80241144 0080A02D */  daddu     $s4, $a0, $zero
/* BDFED8 80241148 AFBF0048 */  sw        $ra, 0x48($sp)
/* BDFEDC 8024114C AFB50044 */  sw        $s5, 0x44($sp)
/* BDFEE0 80241150 AFB3003C */  sw        $s3, 0x3c($sp)
/* BDFEE4 80241154 AFB20038 */  sw        $s2, 0x38($sp)
/* BDFEE8 80241158 AFB10034 */  sw        $s1, 0x34($sp)
/* BDFEEC 8024115C AFB00030 */  sw        $s0, 0x30($sp)
/* BDFEF0 80241160 8E930148 */  lw        $s3, 0x148($s4)
/* BDFEF4 80241164 86640008 */  lh        $a0, 8($s3)
/* BDFEF8 80241168 8E90000C */  lw        $s0, 0xc($s4)
/* BDFEFC 8024116C 0C00EABB */  jal       get_npc_unsafe
/* BDFF00 80241170 00A0882D */   daddu    $s1, $a1, $zero
/* BDFF04 80241174 0280202D */  daddu     $a0, $s4, $zero
/* BDFF08 80241178 8E050000 */  lw        $a1, ($s0)
/* BDFF0C 8024117C 0C0B1EAF */  jal       get_variable
/* BDFF10 80241180 0040A82D */   daddu    $s5, $v0, $zero
/* BDFF14 80241184 AFA00010 */  sw        $zero, 0x10($sp)
/* BDFF18 80241188 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BDFF1C 8024118C 8C630094 */  lw        $v1, 0x94($v1)
/* BDFF20 80241190 AFA30014 */  sw        $v1, 0x14($sp)
/* BDFF24 80241194 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BDFF28 80241198 8C630080 */  lw        $v1, 0x80($v1)
/* BDFF2C 8024119C AFA30018 */  sw        $v1, 0x18($sp)
/* BDFF30 802411A0 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BDFF34 802411A4 8C630088 */  lw        $v1, 0x88($v1)
/* BDFF38 802411A8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BDFF3C 802411AC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BDFF40 802411B0 8C63008C */  lw        $v1, 0x8c($v1)
/* BDFF44 802411B4 27B20010 */  addiu     $s2, $sp, 0x10
/* BDFF48 802411B8 AFA30020 */  sw        $v1, 0x20($sp)
/* BDFF4C 802411BC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* BDFF50 802411C0 3C0142C8 */  lui       $at, 0x42c8
/* BDFF54 802411C4 44810000 */  mtc1      $at, $f0
/* BDFF58 802411C8 8C630090 */  lw        $v1, 0x90($v1)
/* BDFF5C 802411CC 0040802D */  daddu     $s0, $v0, $zero
/* BDFF60 802411D0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BDFF64 802411D4 A7A0002C */  sh        $zero, 0x2c($sp)
/* BDFF68 802411D8 12200007 */  beqz      $s1, .L802411F8
/* BDFF6C 802411DC AFA30024 */   sw       $v1, 0x24($sp)
/* BDFF70 802411E0 AE800070 */  sw        $zero, 0x70($s4)
/* BDFF74 802411E4 8EA20000 */  lw        $v0, ($s5)
/* BDFF78 802411E8 2403F7FF */  addiu     $v1, $zero, -0x801
/* BDFF7C 802411EC A6A0008E */  sh        $zero, 0x8e($s5)
/* BDFF80 802411F0 00431024 */  and       $v0, $v0, $v1
/* BDFF84 802411F4 AEA20000 */  sw        $v0, ($s5)
.L802411F8:
/* BDFF88 802411F8 8E830070 */  lw        $v1, 0x70($s4)
/* BDFF8C 802411FC 2C620005 */  sltiu     $v0, $v1, 5
/* BDFF90 80241200 1040001E */  beqz      $v0, .L8024127C
/* BDFF94 80241204 00031080 */   sll      $v0, $v1, 2
/* BDFF98 80241208 3C018024 */  lui       $at, 0x8024
/* BDFF9C 8024120C 00220821 */  addu      $at, $at, $v0
/* BDFFA0 80241210 8C224A00 */  lw        $v0, 0x4a00($at)
/* BDFFA4 80241214 00400008 */  jr        $v0
/* BDFFA8 80241218 00000000 */   nop      
/* BDFFAC 8024121C 0280202D */  daddu     $a0, $s4, $zero
/* BDFFB0 80241220 0200282D */  daddu     $a1, $s0, $zero
/* BDFFB4 80241224 0C090000 */  jal       func_80240000
/* BDFFB8 80241228 0240302D */   daddu    $a2, $s2, $zero
/* BDFFBC 8024122C 0280202D */  daddu     $a0, $s4, $zero
/* BDFFC0 80241230 0200282D */  daddu     $a1, $s0, $zero
/* BDFFC4 80241234 0C0903A4 */  jal       func_80240E90
/* BDFFC8 80241238 0240302D */   daddu    $a2, $s2, $zero
/* BDFFCC 8024123C 0809049F */  j         .L8024127C
/* BDFFD0 80241240 00000000 */   nop      
/* BDFFD4 80241244 0280202D */  daddu     $a0, $s4, $zero
/* BDFFD8 80241248 0200282D */  daddu     $a1, $s0, $zero
/* BDFFDC 8024124C 0C090100 */  jal       func_80240400
/* BDFFE0 80241250 0240302D */   daddu    $a2, $s2, $zero
/* BDFFE4 80241254 0280202D */  daddu     $a0, $s4, $zero
/* BDFFE8 80241258 0200282D */  daddu     $a1, $s0, $zero
/* BDFFEC 8024125C 0C09041A */  jal       func_80241068
/* BDFFF0 80241260 0240302D */   daddu    $a2, $s2, $zero
/* BDFFF4 80241264 0809049F */  j         .L8024127C
/* BDFFF8 80241268 00000000 */   nop      
/* BDFFFC 8024126C 0280202D */  daddu     $a0, $s4, $zero
/* BE0000 80241270 0200282D */  daddu     $a1, $s0, $zero
/* BE0004 80241274 0C09019F */  jal       func_8024067C
/* BE0008 80241278 0240302D */   daddu    $a2, $s2, $zero
.L8024127C:
/* BE000C 8024127C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* BE0010 80241280 4600008D */  trunc.w.s $f2, $f0
/* BE0014 80241284 E662006C */  swc1      $f2, 0x6c($s3)
/* BE0018 80241288 8FBF0048 */  lw        $ra, 0x48($sp)
/* BE001C 8024128C 8FB50044 */  lw        $s5, 0x44($sp)
/* BE0020 80241290 8FB40040 */  lw        $s4, 0x40($sp)
/* BE0024 80241294 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE0028 80241298 8FB20038 */  lw        $s2, 0x38($sp)
/* BE002C 8024129C 8FB10034 */  lw        $s1, 0x34($sp)
/* BE0030 802412A0 8FB00030 */  lw        $s0, 0x30($sp)
/* BE0034 802412A4 0000102D */  daddu     $v0, $zero, $zero
/* BE0038 802412A8 03E00008 */  jr        $ra
/* BE003C 802412AC 27BD0050 */   addiu    $sp, $sp, 0x50
