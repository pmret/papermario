.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3728
/* 104FA8 802E3728 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 104FAC 802E372C AFB10014 */  sw        $s1, 0x14($sp)
/* 104FB0 802E3730 0080882D */  daddu     $s1, $a0, $zero
/* 104FB4 802E3734 AFBF0018 */  sw        $ra, 0x18($sp)
/* 104FB8 802E3738 AFB00010 */  sw        $s0, 0x10($sp)
/* 104FBC 802E373C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 104FC0 802E3740 0C0B8E80 */  jal       func_802E3A00
/* 104FC4 802E3744 8E300040 */   lw       $s0, 0x40($s1)
/* 104FC8 802E3748 3C0140C9 */  lui       $at, 0x40c9
/* 104FCC 802E374C 34210FD0 */  ori       $at, $at, 0xfd0
/* 104FD0 802E3750 44810000 */  mtc1      $at, $f0
/* 104FD4 802E3754 C60C0018 */  lwc1      $f12, 0x18($s0)
/* 104FD8 802E3758 46006302 */  mul.s     $f12, $f12, $f0
/* 104FDC 802E375C 00000000 */  nop       
/* 104FE0 802E3760 C634004C */  lwc1      $f20, 0x4c($s1)
/* 104FE4 802E3764 3C0143B4 */  lui       $at, 0x43b4
/* 104FE8 802E3768 44810000 */  mtc1      $at, $f0
/* 104FEC 802E376C 4600A521 */  cvt.d.s   $f20, $f20
/* 104FF0 802E3770 0C00A85B */  jal       sin_rad
/* 104FF4 802E3774 46006303 */   div.s    $f12, $f12, $f0
/* 104FF8 802E3778 46000021 */  cvt.d.s   $f0, $f0
/* 104FFC 802E377C 46200000 */  add.d     $f0, $f0, $f0
/* 105000 802E3780 4620A500 */  add.d     $f20, $f20, $f0
/* 105004 802E3784 3C014270 */  lui       $at, 0x4270
/* 105008 802E3788 44810000 */  mtc1      $at, $f0
/* 10500C 802E378C 4620A520 */  cvt.s.d   $f20, $f20
/* 105010 802E3790 E634004C */  swc1      $f20, 0x4c($s1)
/* 105014 802E3794 C6020018 */  lwc1      $f2, 0x18($s0)
/* 105018 802E3798 46001300 */  add.s     $f12, $f2, $f0
/* 10501C 802E379C 3C0143E1 */  lui       $at, 0x43e1
/* 105020 802E37A0 44810000 */  mtc1      $at, $f0
/* 105024 802E37A4 00000000 */  nop       
/* 105028 802E37A8 460C003C */  c.lt.s    $f0, $f12
/* 10502C 802E37AC 00000000 */  nop       
/* 105030 802E37B0 45000006 */  bc1f      .L802E37CC
/* 105034 802E37B4 E60C0018 */   swc1     $f12, 0x18($s0)
/* 105038 802E37B8 0C00A6C9 */  jal       clamp_angle
/* 10503C 802E37BC 00000000 */   nop      
/* 105040 802E37C0 E6000018 */  swc1      $f0, 0x18($s0)
/* 105044 802E37C4 0C043F5A */  jal       func_8010FD68
/* 105048 802E37C8 0220202D */   daddu    $a0, $s1, $zero
.L802E37CC:
/* 10504C 802E37CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 105050 802E37D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 105054 802E37D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 105058 802E37D8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 10505C 802E37DC 03E00008 */  jr        $ra
/* 105060 802E37E0 27BD0028 */   addiu    $sp, $sp, 0x28
