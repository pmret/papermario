.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243578_C4A158
/* C4A158 80243578 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* C4A15C 8024357C AFB40050 */  sw        $s4, 0x50($sp)
/* C4A160 80243580 0080A02D */  daddu     $s4, $a0, $zero
/* C4A164 80243584 AFBF0058 */  sw        $ra, 0x58($sp)
/* C4A168 80243588 AFB50054 */  sw        $s5, 0x54($sp)
/* C4A16C 8024358C AFB3004C */  sw        $s3, 0x4c($sp)
/* C4A170 80243590 AFB20048 */  sw        $s2, 0x48($sp)
/* C4A174 80243594 AFB10044 */  sw        $s1, 0x44($sp)
/* C4A178 80243598 AFB00040 */  sw        $s0, 0x40($sp)
/* C4A17C 8024359C 8E920148 */  lw        $s2, 0x148($s4)
/* C4A180 802435A0 86440008 */  lh        $a0, 8($s2)
/* C4A184 802435A4 0C00EABB */  jal       get_npc_unsafe
/* C4A188 802435A8 00A0802D */   daddu    $s0, $a1, $zero
/* C4A18C 802435AC 8E83000C */  lw        $v1, 0xc($s4)
/* C4A190 802435B0 0280202D */  daddu     $a0, $s4, $zero
/* C4A194 802435B4 8C650000 */  lw        $a1, ($v1)
/* C4A198 802435B8 0C0B1EAF */  jal       get_variable
/* C4A19C 802435BC 0040A82D */   daddu    $s5, $v0, $zero
/* C4A1A0 802435C0 AFA00020 */  sw        $zero, 0x20($sp)
/* C4A1A4 802435C4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4A1A8 802435C8 8C630030 */  lw        $v1, 0x30($v1)
/* C4A1AC 802435CC AFA30024 */  sw        $v1, 0x24($sp)
/* C4A1B0 802435D0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4A1B4 802435D4 8C63001C */  lw        $v1, 0x1c($v1)
/* C4A1B8 802435D8 AFA30028 */  sw        $v1, 0x28($sp)
/* C4A1BC 802435DC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4A1C0 802435E0 8C630024 */  lw        $v1, 0x24($v1)
/* C4A1C4 802435E4 AFA3002C */  sw        $v1, 0x2c($sp)
/* C4A1C8 802435E8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4A1CC 802435EC 8C630028 */  lw        $v1, 0x28($v1)
/* C4A1D0 802435F0 27B30020 */  addiu     $s3, $sp, 0x20
/* C4A1D4 802435F4 AFA30030 */  sw        $v1, 0x30($sp)
/* C4A1D8 802435F8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C4A1DC 802435FC 3C0142FA */  lui       $at, 0x42fa
/* C4A1E0 80243600 44810000 */  mtc1      $at, $f0
/* C4A1E4 80243604 8C63002C */  lw        $v1, 0x2c($v1)
/* C4A1E8 80243608 0040882D */  daddu     $s1, $v0, $zero
/* C4A1EC 8024360C E7A00038 */  swc1      $f0, 0x38($sp)
/* C4A1F0 80243610 A7A0003C */  sh        $zero, 0x3c($sp)
/* C4A1F4 80243614 12000007 */  beqz      $s0, .L80243634
/* C4A1F8 80243618 AFA30034 */   sw       $v1, 0x34($sp)
/* C4A1FC 8024361C AE800070 */  sw        $zero, 0x70($s4)
/* C4A200 80243620 02A0202D */  daddu     $a0, $s5, $zero
/* C4A204 80243624 0240282D */  daddu     $a1, $s2, $zero
/* C4A208 80243628 0280302D */  daddu     $a2, $s4, $zero
/* C4A20C 8024362C 0C090983 */  jal       func_8024260C_C491EC
/* C4A210 80243630 0220382D */   daddu    $a3, $s1, $zero
.L80243634:
/* C4A214 80243634 8E830070 */  lw        $v1, 0x70($s4)
/* C4A218 80243638 2C620020 */  sltiu     $v0, $v1, 0x20
/* C4A21C 8024363C 10400060 */  beqz      $v0, L802437C0_C4A3A0
/* C4A220 80243640 00031080 */   sll      $v0, $v1, 2
/* C4A224 80243644 3C018024 */  lui       $at, %hi(jtbl_80245728_C4C308)
/* C4A228 80243648 00220821 */  addu      $at, $at, $v0
/* C4A22C 8024364C 8C225728 */  lw        $v0, %lo(jtbl_80245728_C4C308)($at)
/* C4A230 80243650 00400008 */  jr        $v0
/* C4A234 80243654 00000000 */   nop
glabel L80243658_C4A238
/* C4A238 80243658 0280202D */  daddu     $a0, $s4, $zero
/* C4A23C 8024365C 0220282D */  daddu     $a1, $s1, $zero
/* C4A240 80243660 0C090509 */  jal       func_80241424_C48004
/* C4A244 80243664 0260302D */   daddu    $a2, $s3, $zero
/* C4A248 80243668 0000282D */  daddu     $a1, $zero, $zero
/* C4A24C 8024366C 00A0302D */  daddu     $a2, $a1, $zero
/* C4A250 80243670 AFA00010 */  sw        $zero, 0x10($sp)
/* C4A254 80243674 AFA00014 */  sw        $zero, 0x14($sp)
/* C4A258 80243678 AFA00018 */  sw        $zero, 0x18($sp)
/* C4A25C 8024367C 8EA40024 */  lw        $a0, 0x24($s5)
/* C4A260 80243680 0C0B7A25 */  jal       func_802DE894
/* C4A264 80243684 00A0382D */   daddu    $a3, $a1, $zero
glabel L80243688_C4A268
/* C4A268 80243688 0280202D */  daddu     $a0, $s4, $zero
/* C4A26C 8024368C 0220282D */  daddu     $a1, $s1, $zero
/* C4A270 80243690 0C090575 */  jal       func_802415D4_C481B4
/* C4A274 80243694 0260302D */   daddu    $a2, $s3, $zero
/* C4A278 80243698 08090DB0 */  j         .L802436C0
/* C4A27C 8024369C 00000000 */   nop
glabel L802436A0_C4A280
/* C4A280 802436A0 0280202D */  daddu     $a0, $s4, $zero
/* C4A284 802436A4 0220282D */  daddu     $a1, $s1, $zero
/* C4A288 802436A8 0C0906FF */  jal       dgb_09_UnkNpcAIFunc1
/* C4A28C 802436AC 0260302D */   daddu    $a2, $s3, $zero
glabel L802436B0_C4A290
/* C4A290 802436B0 0280202D */  daddu     $a0, $s4, $zero
/* C4A294 802436B4 0220282D */  daddu     $a1, $s1, $zero
/* C4A298 802436B8 0C09072F */  jal       func_80241CBC_C4889C
/* C4A29C 802436BC 0260302D */   daddu    $a2, $s3, $zero
.L802436C0:
/* C4A2A0 802436C0 8E830070 */  lw        $v1, 0x70($s4)
/* C4A2A4 802436C4 2402000C */  addiu     $v0, $zero, 0xc
/* C4A2A8 802436C8 1462003D */  bne       $v1, $v0, L802437C0_C4A3A0
/* C4A2AC 802436CC 24020006 */   addiu    $v0, $zero, 6
/* C4A2B0 802436D0 08090DF0 */  j         L802437C0_C4A3A0
/* C4A2B4 802436D4 A6A2008E */   sh       $v0, 0x8e($s5)
glabel L802436D8_C4A2B8
/* C4A2B8 802436D8 0280202D */  daddu     $a0, $s4, $zero
/* C4A2BC 802436DC 0220282D */  daddu     $a1, $s1, $zero
/* C4A2C0 802436E0 0C090A47 */  jal       func_8024291C_C494FC
/* C4A2C4 802436E4 0260302D */   daddu    $a2, $s3, $zero
/* C4A2C8 802436E8 8E830070 */  lw        $v1, 0x70($s4)
/* C4A2CC 802436EC 2402000D */  addiu     $v0, $zero, 0xd
/* C4A2D0 802436F0 14620033 */  bne       $v1, $v0, L802437C0_C4A3A0
/* C4A2D4 802436F4 00000000 */   nop
glabel L802436F8_C4A2D8
/* C4A2D8 802436F8 0280202D */  daddu     $a0, $s4, $zero
/* C4A2DC 802436FC 0220282D */  daddu     $a1, $s1, $zero
/* C4A2E0 80243700 0C090A9D */  jal       func_80242A74_C49654
/* C4A2E4 80243704 0260302D */   daddu    $a2, $s3, $zero
/* C4A2E8 80243708 08090DF0 */  j         L802437C0_C4A3A0
/* C4A2EC 8024370C 00000000 */   nop
glabel L80243710_C4A2F0
/* C4A2F0 80243710 0280202D */  daddu     $a0, $s4, $zero
/* C4A2F4 80243714 0220282D */  daddu     $a1, $s1, $zero
/* C4A2F8 80243718 0C090ADE */  jal       func_80242B78_C49758
/* C4A2FC 8024371C 0260302D */   daddu    $a2, $s3, $zero
/* C4A300 80243720 8E830070 */  lw        $v1, 0x70($s4)
/* C4A304 80243724 2402000F */  addiu     $v0, $zero, 0xf
/* C4A308 80243728 14620025 */  bne       $v1, $v0, L802437C0_C4A3A0
/* C4A30C 8024372C 00000000 */   nop
glabel L80243730_C4A310
/* C4A310 80243730 0280202D */  daddu     $a0, $s4, $zero
/* C4A314 80243734 0220282D */  daddu     $a1, $s1, $zero
/* C4A318 80243738 0C090B07 */  jal       func_80242C1C_C497FC
/* C4A31C 8024373C 0260302D */   daddu    $a2, $s3, $zero
/* C4A320 80243740 08090DF0 */  j         L802437C0_C4A3A0
/* C4A324 80243744 00000000 */   nop
glabel L80243748_C4A328
/* C4A328 80243748 0280202D */  daddu     $a0, $s4, $zero
/* C4A32C 8024374C 0220282D */  daddu     $a1, $s1, $zero
/* C4A330 80243750 0C090BAE */  jal       func_80242EB8_C49A98
/* C4A334 80243754 0260302D */   daddu    $a2, $s3, $zero
glabel L80243758_C4A338
/* C4A338 80243758 0280202D */  daddu     $a0, $s4, $zero
/* C4A33C 8024375C 0220282D */  daddu     $a1, $s1, $zero
/* C4A340 80243760 0C090BDC */  jal       func_80242F70_C49B50
/* C4A344 80243764 0260302D */   daddu    $a2, $s3, $zero
/* C4A348 80243768 08090DF0 */  j         L802437C0_C4A3A0
/* C4A34C 8024376C 00000000 */   nop
glabel L80243770_C4A350
/* C4A350 80243770 0280202D */  daddu     $a0, $s4, $zero
/* C4A354 80243774 0220282D */  daddu     $a1, $s1, $zero
/* C4A358 80243778 0C090C3C */  jal       func_802430F0_C49CD0
/* C4A35C 8024377C 0260302D */   daddu    $a2, $s3, $zero
/* C4A360 80243780 08090DF0 */  j         L802437C0_C4A3A0
/* C4A364 80243784 00000000 */   nop
glabel L80243788_C4A368
/* C4A368 80243788 0280202D */  daddu     $a0, $s4, $zero
/* C4A36C 8024378C 0220282D */  daddu     $a1, $s1, $zero
/* C4A370 80243790 0C090C4E */  jal       func_80243138_C49D18
/* C4A374 80243794 0260302D */   daddu    $a2, $s3, $zero
/* C4A378 80243798 08090DF0 */  j         L802437C0_C4A3A0
/* C4A37C 8024379C 00000000 */   nop
glabel L802437A0_C4A380
/* C4A380 802437A0 0280202D */  daddu     $a0, $s4, $zero
/* C4A384 802437A4 0220282D */  daddu     $a1, $s1, $zero
/* C4A388 802437A8 0C090C6E */  jal       func_802431B8_C49D98
/* C4A38C 802437AC 0260302D */   daddu    $a2, $s3, $zero
glabel L802437B0_C4A390
/* C4A390 802437B0 0280202D */  daddu     $a0, $s4, $zero
/* C4A394 802437B4 0220282D */  daddu     $a1, $s1, $zero
/* C4A398 802437B8 0C090C98 */  jal       func_80243260_C49E40
/* C4A39C 802437BC 0260302D */   daddu    $a2, $s3, $zero
glabel L802437C0_C4A3A0
/* C4A3A0 802437C0 8E820070 */  lw        $v0, 0x70($s4)
/* C4A3A4 802437C4 8FBF0058 */  lw        $ra, 0x58($sp)
/* C4A3A8 802437C8 8FB50054 */  lw        $s5, 0x54($sp)
/* C4A3AC 802437CC 8FB40050 */  lw        $s4, 0x50($sp)
/* C4A3B0 802437D0 8FB3004C */  lw        $s3, 0x4c($sp)
/* C4A3B4 802437D4 8FB20048 */  lw        $s2, 0x48($sp)
/* C4A3B8 802437D8 8FB10044 */  lw        $s1, 0x44($sp)
/* C4A3BC 802437DC 8FB00040 */  lw        $s0, 0x40($sp)
/* C4A3C0 802437E0 38420064 */  xori      $v0, $v0, 0x64
/* C4A3C4 802437E4 2C420001 */  sltiu     $v0, $v0, 1
/* C4A3C8 802437E8 00021040 */  sll       $v0, $v0, 1
/* C4A3CC 802437EC 03E00008 */  jr        $ra
/* C4A3D0 802437F0 27BD0060 */   addiu    $sp, $sp, 0x60
/* C4A3D4 802437F4 00000000 */  nop
/* C4A3D8 802437F8 00000000 */  nop
/* C4A3DC 802437FC 00000000 */  nop
