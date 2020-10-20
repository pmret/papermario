.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408A0_BD4110
/* BD4110 802408A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD4114 802408A4 AFB10014 */  sw        $s1, 0x14($sp)
/* BD4118 802408A8 0080882D */  daddu     $s1, $a0, $zero
/* BD411C 802408AC AFBF0018 */  sw        $ra, 0x18($sp)
/* BD4120 802408B0 AFB00010 */  sw        $s0, 0x10($sp)
/* BD4124 802408B4 0C00EABB */  jal       get_npc_unsafe
/* BD4128 802408B8 8E24014C */   lw       $a0, 0x14c($s1)
/* BD412C 802408BC 24040004 */  addiu     $a0, $zero, 4
/* BD4130 802408C0 0C00AB39 */  jal       heap_malloc
/* BD4134 802408C4 0040802D */   daddu    $s0, $v0, $zero
/* BD4138 802408C8 3C0142FA */  lui       $at, 0x42fa
/* BD413C 802408CC 44810000 */  mtc1      $at, $f0
/* BD4140 802408D0 3C01C45A */  lui       $at, 0xc45a
/* BD4144 802408D4 3421C000 */  ori       $at, $at, 0xc000
/* BD4148 802408D8 44811000 */  mtc1      $at, $f2
/* BD414C 802408DC 0040182D */  daddu     $v1, $v0, $zero
/* BD4150 802408E0 AE030020 */  sw        $v1, 0x20($s0)
/* BD4154 802408E4 AC600000 */  sw        $zero, ($v1)
/* BD4158 802408E8 2403003C */  addiu     $v1, $zero, 0x3c
/* BD415C 802408EC AE00000C */  sw        $zero, 0xc($s0)
/* BD4160 802408F0 AE000038 */  sw        $zero, 0x38($s0)
/* BD4164 802408F4 AE000040 */  sw        $zero, 0x40($s0)
/* BD4168 802408F8 A603008E */  sh        $v1, 0x8e($s0)
/* BD416C 802408FC E6000010 */  swc1      $f0, 0x10($s0)
/* BD4170 80240900 E602003C */  swc1      $f2, 0x3c($s0)
/* BD4174 80240904 AE200074 */  sw        $zero, 0x74($s1)
/* BD4178 80240908 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD417C 8024090C 8FB10014 */  lw        $s1, 0x14($sp)
/* BD4180 80240910 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4184 80240914 24020002 */  addiu     $v0, $zero, 2
/* BD4188 80240918 03E00008 */  jr        $ra
/* BD418C 8024091C 27BD0020 */   addiu    $sp, $sp, 0x20
