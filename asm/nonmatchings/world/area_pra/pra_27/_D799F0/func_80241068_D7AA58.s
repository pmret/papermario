.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241068_D7AA58
/* D7AA58 80241068 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7AA5C 8024106C AFB10014 */  sw        $s1, 0x14($sp)
/* D7AA60 80241070 0080882D */  daddu     $s1, $a0, $zero
/* D7AA64 80241074 AFBF001C */  sw        $ra, 0x1c($sp)
/* D7AA68 80241078 AFB20018 */  sw        $s2, 0x18($sp)
/* D7AA6C 8024107C AFB00010 */  sw        $s0, 0x10($sp)
/* D7AA70 80241080 8E240084 */  lw        $a0, 0x84($s1)
/* D7AA74 80241084 0C04C3D6 */  jal       get_item_entity
/* D7AA78 80241088 00A0802D */   daddu    $s0, $a1, $zero
/* D7AA7C 8024108C 12000005 */  beqz      $s0, .L802410A4
/* D7AA80 80241090 0040902D */   daddu    $s2, $v0, $zero
/* D7AA84 80241094 C640000C */  lwc1      $f0, 0xc($s2)
/* D7AA88 80241098 AE200074 */  sw        $zero, 0x74($s1)
/* D7AA8C 8024109C AE20007C */  sw        $zero, 0x7c($s1)
/* D7AA90 802410A0 E6200078 */  swc1      $f0, 0x78($s1)
.L802410A4:
/* D7AA94 802410A4 8E230074 */  lw        $v1, 0x74($s1)
/* D7AA98 802410A8 10600005 */  beqz      $v1, .L802410C0
/* D7AA9C 802410AC 24020001 */   addiu    $v0, $zero, 1
/* D7AAA0 802410B0 10620024 */  beq       $v1, $v0, .L80241144
/* D7AAA4 802410B4 00000000 */   nop      
/* D7AAA8 802410B8 08090467 */  j         .L8024119C
/* D7AAAC 802410BC 00000000 */   nop      
.L802410C0:
/* D7AAB0 802410C0 3C013FC9 */  lui       $at, 0x3fc9
/* D7AAB4 802410C4 34210FD8 */  ori       $at, $at, 0xfd8
/* D7AAB8 802410C8 44810000 */  mtc1      $at, $f0
/* D7AABC 802410CC C62C007C */  lwc1      $f12, 0x7c($s1)
/* D7AAC0 802410D0 46806320 */  cvt.s.w   $f12, $f12
/* D7AAC4 802410D4 46006302 */  mul.s     $f12, $f12, $f0
/* D7AAC8 802410D8 00000000 */  nop       
/* D7AACC 802410DC 3C0141F0 */  lui       $at, 0x41f0
/* D7AAD0 802410E0 44810000 */  mtc1      $at, $f0
/* D7AAD4 802410E4 0C00A874 */  jal       cos_rad
/* D7AAD8 802410E8 46006303 */   div.s    $f12, $f12, $f0
/* D7AADC 802410EC 3C013F80 */  lui       $at, 0x3f80
/* D7AAE0 802410F0 44811000 */  mtc1      $at, $f2
/* D7AAE4 802410F4 00000000 */  nop       
/* D7AAE8 802410F8 46001081 */  sub.s     $f2, $f2, $f0
/* D7AAEC 802410FC 3C0141A0 */  lui       $at, 0x41a0
/* D7AAF0 80241100 44810000 */  mtc1      $at, $f0
/* D7AAF4 80241104 00000000 */  nop       
/* D7AAF8 80241108 46001082 */  mul.s     $f2, $f2, $f0
/* D7AAFC 8024110C 00000000 */  nop       
/* D7AB00 80241110 C6200078 */  lwc1      $f0, 0x78($s1)
/* D7AB04 80241114 46020000 */  add.s     $f0, $f0, $f2
/* D7AB08 80241118 E640000C */  swc1      $f0, 0xc($s2)
/* D7AB0C 8024111C 8E23007C */  lw        $v1, 0x7c($s1)
/* D7AB10 80241120 2402001E */  addiu     $v0, $zero, 0x1e
/* D7AB14 80241124 14620005 */  bne       $v1, $v0, .L8024113C
/* D7AB18 80241128 24620001 */   addiu    $v0, $v1, 1
/* D7AB1C 8024112C 24020001 */  addiu     $v0, $zero, 1
/* D7AB20 80241130 AE220074 */  sw        $v0, 0x74($s1)
/* D7AB24 80241134 08090467 */  j         .L8024119C
/* D7AB28 80241138 AE20007C */   sw       $zero, 0x7c($s1)
.L8024113C:
/* D7AB2C 8024113C 08090467 */  j         .L8024119C
/* D7AB30 80241140 AE22007C */   sw       $v0, 0x7c($s1)
.L80241144:
/* D7AB34 80241144 C62C007C */  lwc1      $f12, 0x7c($s1)
/* D7AB38 80241148 0C00A8D4 */  jal       cos_deg
/* D7AB3C 8024114C 46806320 */   cvt.s.w  $f12, $f12
/* D7AB40 80241150 3C014040 */  lui       $at, 0x4040
/* D7AB44 80241154 44811000 */  mtc1      $at, $f2
/* D7AB48 80241158 00000000 */  nop       
/* D7AB4C 8024115C 46020002 */  mul.s     $f0, $f0, $f2
/* D7AB50 80241160 00000000 */  nop       
/* D7AB54 80241164 3C014188 */  lui       $at, 0x4188
/* D7AB58 80241168 44812000 */  mtc1      $at, $f4
/* D7AB5C 8024116C C6220078 */  lwc1      $f2, 0x78($s1)
/* D7AB60 80241170 46041080 */  add.s     $f2, $f2, $f4
/* D7AB64 80241174 46001080 */  add.s     $f2, $f2, $f0
/* D7AB68 80241178 E642000C */  swc1      $f2, 0xc($s2)
/* D7AB6C 8024117C 8E22007C */  lw        $v0, 0x7c($s1)
/* D7AB70 80241180 24420009 */  addiu     $v0, $v0, 9
/* D7AB74 80241184 44826000 */  mtc1      $v0, $f12
/* D7AB78 80241188 00000000 */  nop       
/* D7AB7C 8024118C 0C00A6C9 */  jal       clamp_angle
/* D7AB80 80241190 46806320 */   cvt.s.w  $f12, $f12
/* D7AB84 80241194 4600018D */  trunc.w.s $f6, $f0
/* D7AB88 80241198 E626007C */  swc1      $f6, 0x7c($s1)
.L8024119C:
/* D7AB8C 8024119C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D7AB90 802411A0 8FB20018 */  lw        $s2, 0x18($sp)
/* D7AB94 802411A4 8FB10014 */  lw        $s1, 0x14($sp)
/* D7AB98 802411A8 8FB00010 */  lw        $s0, 0x10($sp)
/* D7AB9C 802411AC 0000102D */  daddu     $v0, $zero, $zero
/* D7ABA0 802411B0 03E00008 */  jr        $ra
/* D7ABA4 802411B4 27BD0020 */   addiu    $sp, $sp, 0x20
