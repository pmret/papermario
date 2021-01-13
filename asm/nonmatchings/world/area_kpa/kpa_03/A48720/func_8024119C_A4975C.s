.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024119C_A4975C
/* A4975C 8024119C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A49760 802411A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* A49764 802411A4 0080982D */  daddu     $s3, $a0, $zero
/* A49768 802411A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* A4976C 802411AC AFB20018 */  sw        $s2, 0x18($sp)
/* A49770 802411B0 AFB10014 */  sw        $s1, 0x14($sp)
/* A49774 802411B4 AFB00010 */  sw        $s0, 0x10($sp)
/* A49778 802411B8 8E720148 */  lw        $s2, 0x148($s3)
/* A4977C 802411BC 0C00EABB */  jal       get_npc_unsafe
/* A49780 802411C0 86440008 */   lh       $a0, 8($s2)
/* A49784 802411C4 0040802D */  daddu     $s0, $v0, $zero
/* A49788 802411C8 8603008E */  lh        $v1, 0x8e($s0)
/* A4978C 802411CC 3C118024 */  lui       $s1, %hi(func_802425E0_A1D6E0)
/* A49790 802411D0 263125E0 */  addiu     $s1, $s1, %lo(func_802425E0_A1D6E0)
/* A49794 802411D4 00031040 */  sll       $v0, $v1, 1
/* A49798 802411D8 00431021 */  addu      $v0, $v0, $v1
/* A4979C 802411DC 00021080 */  sll       $v0, $v0, 2
/* A497A0 802411E0 3C018024 */  lui       $at, %hi(func_802425E0_A1D6E0)
/* A497A4 802411E4 00220821 */  addu      $at, $at, $v0
/* A497A8 802411E8 C42025E0 */  lwc1      $f0, %lo(func_802425E0_A1D6E0)($at)
/* A497AC 802411EC 00031040 */  sll       $v0, $v1, 1
/* A497B0 802411F0 00431021 */  addu      $v0, $v0, $v1
/* A497B4 802411F4 00021080 */  sll       $v0, $v0, 2
/* A497B8 802411F8 E6000054 */  swc1      $f0, 0x54($s0)
/* A497BC 802411FC 3C018024 */  lui       $at, %hi(D_802425E4)
/* A497C0 80241200 00220821 */  addu      $at, $at, $v0
/* A497C4 80241204 C42025E4 */  lwc1      $f0, %lo(D_802425E4)($at)
/* A497C8 80241208 00031040 */  sll       $v0, $v1, 1
/* A497CC 8024120C 00431021 */  addu      $v0, $v0, $v1
/* A497D0 80241210 9603008E */  lhu       $v1, 0x8e($s0)
/* A497D4 80241214 00021080 */  sll       $v0, $v0, 2
/* A497D8 80241218 E6000058 */  swc1      $f0, 0x58($s0)
/* A497DC 8024121C 3C018024 */  lui       $at, %hi(D_802425E8)
/* A497E0 80241220 00220821 */  addu      $at, $at, $v0
/* A497E4 80241224 902225E8 */  lbu       $v0, %lo(D_802425E8)($at)
/* A497E8 80241228 24630001 */  addiu     $v1, $v1, 1
/* A497EC 8024122C A603008E */  sh        $v1, 0x8e($s0)
/* A497F0 80241230 00031C00 */  sll       $v1, $v1, 0x10
/* A497F4 80241234 00031C03 */  sra       $v1, $v1, 0x10
/* A497F8 80241238 A20200AC */  sb        $v0, 0xac($s0)
/* A497FC 8024123C 24020004 */  addiu     $v0, $zero, 4
/* A49800 80241240 14620007 */  bne       $v1, $v0, .L80241260
/* A49804 80241244 00000000 */   nop
/* A49808 80241248 0C00EAFF */  jal       disable_npc_shadow
/* A4980C 8024124C 0200202D */   daddu    $a0, $s0, $zero
/* A49810 80241250 8E420000 */  lw        $v0, ($s2)
/* A49814 80241254 3C031F10 */  lui       $v1, 0x1f10
/* A49818 80241258 00431025 */  or        $v0, $v0, $v1
/* A4981C 8024125C AE420000 */  sw        $v0, ($s2)
.L80241260:
/* A49820 80241260 8602008E */  lh        $v0, 0x8e($s0)
/* A49824 80241264 00021840 */  sll       $v1, $v0, 1
/* A49828 80241268 00621821 */  addu      $v1, $v1, $v0
/* A4982C 8024126C 00031880 */  sll       $v1, $v1, 2
/* A49830 80241270 00711821 */  addu      $v1, $v1, $s1
/* A49834 80241274 90620008 */  lbu       $v0, 8($v1)
/* A49838 80241278 1440000C */  bnez      $v0, .L802412AC
/* A4983C 8024127C 240200FF */   addiu    $v0, $zero, 0xff
/* A49840 80241280 A20200AC */  sb        $v0, 0xac($s0)
/* A49844 80241284 24020005 */  addiu     $v0, $zero, 5
/* A49848 80241288 8E030000 */  lw        $v1, ($s0)
/* A4984C 8024128C 3C013F80 */  lui       $at, 0x3f80
/* A49850 80241290 44810000 */  mtc1      $at, $f0
/* A49854 80241294 34630002 */  ori       $v1, $v1, 2
/* A49858 80241298 E6000054 */  swc1      $f0, 0x54($s0)
/* A4985C 8024129C E6000058 */  swc1      $f0, 0x58($s0)
/* A49860 802412A0 E600005C */  swc1      $f0, 0x5c($s0)
/* A49864 802412A4 AE030000 */  sw        $v1, ($s0)
/* A49868 802412A8 AE620070 */  sw        $v0, 0x70($s3)
.L802412AC:
/* A4986C 802412AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* A49870 802412B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* A49874 802412B4 8FB20018 */  lw        $s2, 0x18($sp)
/* A49878 802412B8 8FB10014 */  lw        $s1, 0x14($sp)
/* A4987C 802412BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A49880 802412C0 03E00008 */  jr        $ra
/* A49884 802412C4 27BD0028 */   addiu    $sp, $sp, 0x28
