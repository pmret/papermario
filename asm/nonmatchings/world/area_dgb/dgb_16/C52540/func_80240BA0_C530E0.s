.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BA0_C530E0
/* C530E0 80240BA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C530E4 80240BA4 AFB20018 */  sw        $s2, 0x18($sp)
/* C530E8 80240BA8 0080902D */  daddu     $s2, $a0, $zero
/* C530EC 80240BAC AFBF001C */  sw        $ra, 0x1c($sp)
/* C530F0 80240BB0 AFB10014 */  sw        $s1, 0x14($sp)
/* C530F4 80240BB4 AFB00010 */  sw        $s0, 0x10($sp)
/* C530F8 80240BB8 8E500148 */  lw        $s0, 0x148($s2)
/* C530FC 80240BBC 86040008 */  lh        $a0, 8($s0)
/* C53100 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* C53104 80240BC4 00A0882D */   daddu    $s1, $a1, $zero
/* C53108 80240BC8 0040182D */  daddu     $v1, $v0, $zero
/* C5310C 80240BCC 9462008E */  lhu       $v0, 0x8e($v1)
/* C53110 80240BD0 2442FFFF */  addiu     $v0, $v0, -1
/* C53114 80240BD4 A462008E */  sh        $v0, 0x8e($v1)
/* C53118 80240BD8 00021400 */  sll       $v0, $v0, 0x10
/* C5311C 80240BDC 1C400015 */  bgtz      $v0, .L80240C34
/* C53120 80240BE0 00000000 */   nop      
/* C53124 80240BE4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C53128 80240BE8 8C420004 */  lw        $v0, 4($v0)
/* C5312C 80240BEC AC620028 */  sw        $v0, 0x28($v1)
/* C53130 80240BF0 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C53134 80240BF4 8C420014 */  lw        $v0, 0x14($v0)
/* C53138 80240BF8 04410004 */  bgez      $v0, .L80240C0C
/* C5313C 80240BFC 00000000 */   nop      
/* C53140 80240C00 C6200000 */  lwc1      $f0, ($s1)
/* C53144 80240C04 0809030B */  j         .L80240C2C
/* C53148 80240C08 E4600018 */   swc1     $f0, 0x18($v1)
.L80240C0C:
/* C5314C 80240C0C 3C018024 */  lui       $at, %hi(D_802431F8)
/* C53150 80240C10 D42231F8 */  ldc1      $f2, %lo(D_802431F8)($at)
/* C53154 80240C14 44820000 */  mtc1      $v0, $f0
/* C53158 80240C18 00000000 */  nop       
/* C5315C 80240C1C 46800021 */  cvt.d.w   $f0, $f0
/* C53160 80240C20 46220003 */  div.d     $f0, $f0, $f2
/* C53164 80240C24 46200020 */  cvt.s.d   $f0, $f0
/* C53168 80240C28 E4600018 */  swc1      $f0, 0x18($v1)
.L80240C2C:
/* C5316C 80240C2C 24020029 */  addiu     $v0, $zero, 0x29
/* C53170 80240C30 AE420070 */  sw        $v0, 0x70($s2)
.L80240C34:
/* C53174 80240C34 8FBF001C */  lw        $ra, 0x1c($sp)
/* C53178 80240C38 8FB20018 */  lw        $s2, 0x18($sp)
/* C5317C 80240C3C 8FB10014 */  lw        $s1, 0x14($sp)
/* C53180 80240C40 8FB00010 */  lw        $s0, 0x10($sp)
/* C53184 80240C44 03E00008 */  jr        $ra
/* C53188 80240C48 27BD0020 */   addiu    $sp, $sp, 0x20
