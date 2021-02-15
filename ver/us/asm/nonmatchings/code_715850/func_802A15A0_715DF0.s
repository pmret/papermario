.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A15A0_715DF0
/* 715DF0 802A15A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 715DF4 802A15A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 715DF8 802A15A8 0080802D */  daddu     $s0, $a0, $zero
/* 715DFC 802A15AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 715E00 802A15B0 8E02000C */  lw        $v0, 0xc($s0)
/* 715E04 802A15B4 0C0B1EAF */  jal       get_variable
/* 715E08 802A15B8 8C450000 */   lw       $a1, ($v0)
/* 715E0C 802A15BC 3C038008 */  lui       $v1, %hi(gItemTable)
/* 715E10 802A15C0 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* 715E14 802A15C4 00021140 */  sll       $v0, $v0, 5
/* 715E18 802A15C8 00431021 */  addu      $v0, $v0, $v1
/* 715E1C 802A15CC 8043001B */  lb        $v1, 0x1b($v0)
/* 715E20 802A15D0 AE0300B0 */  sw        $v1, 0xb0($s0)
/* 715E24 802A15D4 8043001C */  lb        $v1, 0x1c($v0)
/* 715E28 802A15D8 AE0300B4 */  sw        $v1, 0xb4($s0)
/* 715E2C 802A15DC 8043001B */  lb        $v1, 0x1b($v0)
/* 715E30 802A15E0 38630001 */  xori      $v1, $v1, 1
/* 715E34 802A15E4 2C630001 */  sltiu     $v1, $v1, 1
/* 715E38 802A15E8 AE0300C0 */  sw        $v1, 0xc0($s0)
/* 715E3C 802A15EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 715E40 802A15F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 715E44 802A15F4 24020002 */  addiu     $v0, $zero, 2
/* 715E48 802A15F8 03E00008 */  jr        $ra
/* 715E4C 802A15FC 27BD0018 */   addiu    $sp, $sp, 0x18
