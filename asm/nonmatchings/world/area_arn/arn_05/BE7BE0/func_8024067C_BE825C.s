.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024067C_BE825C
/* BE825C 8024067C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE8260 80240680 AFB10014 */  sw        $s1, 0x14($sp)
/* BE8264 80240684 0080882D */  daddu     $s1, $a0, $zero
/* BE8268 80240688 AFBF001C */  sw        $ra, 0x1c($sp)
/* BE826C 8024068C AFB20018 */  sw        $s2, 0x18($sp)
/* BE8270 80240690 AFB00010 */  sw        $s0, 0x10($sp)
/* BE8274 80240694 8E300148 */  lw        $s0, 0x148($s1)
/* BE8278 80240698 86040008 */  lh        $a0, 8($s0)
/* BE827C 8024069C 0C00EABB */  jal       get_npc_unsafe
/* BE8280 802406A0 00A0902D */   daddu    $s2, $a1, $zero
/* BE8284 802406A4 8E230078 */  lw        $v1, 0x78($s1)
/* BE8288 802406A8 24630001 */  addiu     $v1, $v1, 1
/* BE828C 802406AC AE230078 */  sw        $v1, 0x78($s1)
/* BE8290 802406B0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* BE8294 802406B4 8C840000 */  lw        $a0, ($a0)
/* BE8298 802406B8 0064182A */  slt       $v1, $v1, $a0
/* BE829C 802406BC 14600002 */  bnez      $v1, .L802406C8
/* BE82A0 802406C0 0040282D */   daddu    $a1, $v0, $zero
/* BE82A4 802406C4 AE200078 */  sw        $zero, 0x78($s1)
.L802406C8:
/* BE82A8 802406C8 8E0200CC */  lw        $v0, 0xcc($s0)
/* BE82AC 802406CC 8C420004 */  lw        $v0, 4($v0)
/* BE82B0 802406D0 ACA20028 */  sw        $v0, 0x28($a1)
/* BE82B4 802406D4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BE82B8 802406D8 8C42007C */  lw        $v0, 0x7c($v0)
/* BE82BC 802406DC 04410004 */  bgez      $v0, .L802406F0
/* BE82C0 802406E0 00000000 */   nop      
/* BE82C4 802406E4 C6400000 */  lwc1      $f0, ($s2)
/* BE82C8 802406E8 080901C4 */  j         .L80240710
/* BE82CC 802406EC E4A00018 */   swc1     $f0, 0x18($a1)
.L802406F0:
/* BE82D0 802406F0 3C018024 */  lui       $at, %hi(D_80245058)
/* BE82D4 802406F4 D4225058 */  ldc1      $f2, %lo(D_80245058)($at)
/* BE82D8 802406F8 44820000 */  mtc1      $v0, $f0
/* BE82DC 802406FC 00000000 */  nop       
/* BE82E0 80240700 46800021 */  cvt.d.w   $f0, $f0
/* BE82E4 80240704 46220003 */  div.d     $f0, $f0, $f2
/* BE82E8 80240708 46200020 */  cvt.s.d   $f0, $f0
/* BE82EC 8024070C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240710:
/* BE82F0 80240710 24020001 */  addiu     $v0, $zero, 1
/* BE82F4 80240714 AE220070 */  sw        $v0, 0x70($s1)
/* BE82F8 80240718 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE82FC 8024071C 8FB20018 */  lw        $s2, 0x18($sp)
/* BE8300 80240720 8FB10014 */  lw        $s1, 0x14($sp)
/* BE8304 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* BE8308 80240728 03E00008 */  jr        $ra
/* BE830C 8024072C 27BD0020 */   addiu    $sp, $sp, 0x20
