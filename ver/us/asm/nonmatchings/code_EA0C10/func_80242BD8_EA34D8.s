.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BD8_EA34D8
/* EA34D8 80242BD8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EA34DC 80242BDC AFB1001C */  sw        $s1, 0x1c($sp)
/* EA34E0 80242BE0 0080882D */  daddu     $s1, $a0, $zero
/* EA34E4 80242BE4 AFBF0034 */  sw        $ra, 0x34($sp)
/* EA34E8 80242BE8 AFB60030 */  sw        $s6, 0x30($sp)
/* EA34EC 80242BEC AFB5002C */  sw        $s5, 0x2c($sp)
/* EA34F0 80242BF0 AFB40028 */  sw        $s4, 0x28($sp)
/* EA34F4 80242BF4 AFB30024 */  sw        $s3, 0x24($sp)
/* EA34F8 80242BF8 AFB20020 */  sw        $s2, 0x20($sp)
/* EA34FC 80242BFC AFB00018 */  sw        $s0, 0x18($sp)
/* EA3500 80242C00 F7B60040 */  sdc1      $f22, 0x40($sp)
/* EA3504 80242C04 F7B40038 */  sdc1      $f20, 0x38($sp)
/* EA3508 80242C08 8E30000C */  lw        $s0, 0xc($s1)
/* EA350C 80242C0C 8E160000 */  lw        $s6, ($s0)
/* EA3510 80242C10 26100004 */  addiu     $s0, $s0, 4
/* EA3514 80242C14 0C0B53A3 */  jal       func_802D4E8C
/* EA3518 80242C18 02C0282D */   daddu    $a1, $s6, $zero
/* EA351C 80242C1C 44820000 */  mtc1      $v0, $f0
/* EA3520 80242C20 00000000 */  nop
/* EA3524 80242C24 46800020 */  cvt.s.w   $f0, $f0
/* EA3528 80242C28 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA352C 80242C2C 8E140000 */  lw        $s4, ($s0)
/* EA3530 80242C30 26100004 */  addiu     $s0, $s0, 4
/* EA3534 80242C34 0220202D */  daddu     $a0, $s1, $zero
/* EA3538 80242C38 0C0B53A3 */  jal       func_802D4E8C
/* EA353C 80242C3C 0280282D */   daddu    $a1, $s4, $zero
/* EA3540 80242C40 0220202D */  daddu     $a0, $s1, $zero
/* EA3544 80242C44 8E150000 */  lw        $s5, ($s0)
/* EA3548 80242C48 4482B000 */  mtc1      $v0, $f22
/* EA354C 80242C4C 00000000 */  nop
/* EA3550 80242C50 4680B5A0 */  cvt.s.w   $f22, $f22
/* EA3554 80242C54 0C0B53A3 */  jal       func_802D4E8C
/* EA3558 80242C58 02A0282D */   daddu    $a1, $s5, $zero
/* EA355C 80242C5C 2404FFFC */  addiu     $a0, $zero, -4
/* EA3560 80242C60 44820000 */  mtc1      $v0, $f0
/* EA3564 80242C64 00000000 */  nop
/* EA3568 80242C68 46800020 */  cvt.s.w   $f0, $f0
/* EA356C 80242C6C 0C00F92F */  jal       func_8003E4BC
/* EA3570 80242C70 E7A00014 */   swc1     $f0, 0x14($sp)
/* EA3574 80242C74 3C048008 */  lui       $a0, %hi(D_8007C760)
/* EA3578 80242C78 8C84C760 */  lw        $a0, %lo(D_8007C760)($a0)
/* EA357C 80242C7C 3C014334 */  lui       $at, 0x4334
/* EA3580 80242C80 44816000 */  mtc1      $at, $f12
/* EA3584 80242C84 00041880 */  sll       $v1, $a0, 2
/* EA3588 80242C88 00641821 */  addu      $v1, $v1, $a0
/* EA358C 80242C8C 00031880 */  sll       $v1, $v1, 2
/* EA3590 80242C90 00641823 */  subu      $v1, $v1, $a0
/* EA3594 80242C94 000320C0 */  sll       $a0, $v1, 3
/* EA3598 80242C98 00641821 */  addu      $v1, $v1, $a0
/* EA359C 80242C9C 000318C0 */  sll       $v1, $v1, 3
/* EA35A0 80242CA0 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EA35A4 80242CA4 00230821 */  addu      $at, $at, $v1
/* EA35A8 80242CA8 C4208DEC */  lwc1      $f0, %lo(D_800B8DEC)($at)
/* EA35AC 80242CAC 460C0300 */  add.s     $f12, $f0, $f12
/* EA35B0 80242CB0 0C00AB85 */  jal       func_8002AE14
/* EA35B4 80242CB4 0040982D */   daddu    $s3, $v0, $zero
/* EA35B8 80242CB8 27B00010 */  addiu     $s0, $sp, 0x10
/* EA35BC 80242CBC 0200202D */  daddu     $a0, $s0, $zero
/* EA35C0 80242CC0 27B20014 */  addiu     $s2, $sp, 0x14
/* EA35C4 80242CC4 0240282D */  daddu     $a1, $s2, $zero
/* EA35C8 80242CC8 3C064170 */  lui       $a2, 0x4170
/* EA35CC 80242CCC 8E67000C */  lw        $a3, 0xc($s3)
/* EA35D0 80242CD0 0C00ACA3 */  jal       func_8002B28C
/* EA35D4 80242CD4 46000506 */   mov.s    $f20, $f0
/* EA35D8 80242CD8 0200202D */  daddu     $a0, $s0, $zero
/* EA35DC 80242CDC 3C064120 */  lui       $a2, 0x4120
/* EA35E0 80242CE0 4407A000 */  mfc1      $a3, $f20
/* EA35E4 80242CE4 0C00ACA3 */  jal       func_8002B28C
/* EA35E8 80242CE8 0240282D */   daddu    $a1, $s2, $zero
/* EA35EC 80242CEC 0220202D */  daddu     $a0, $s1, $zero
/* EA35F0 80242CF0 C7A00010 */  lwc1      $f0, 0x10($sp)
/* EA35F4 80242CF4 4600008D */  trunc.w.s $f2, $f0
/* EA35F8 80242CF8 44061000 */  mfc1      $a2, $f2
/* EA35FC 80242CFC 0C0B551A */  jal       func_802D5468
/* EA3600 80242D00 02C0282D */   daddu    $a1, $s6, $zero
/* EA3604 80242D04 0220202D */  daddu     $a0, $s1, $zero
/* EA3608 80242D08 4600B08D */  trunc.w.s $f2, $f22
/* EA360C 80242D0C 44061000 */  mfc1      $a2, $f2
/* EA3610 80242D10 0C0B551A */  jal       func_802D5468
/* EA3614 80242D14 0280282D */   daddu    $a1, $s4, $zero
/* EA3618 80242D18 0220202D */  daddu     $a0, $s1, $zero
/* EA361C 80242D1C C7A00014 */  lwc1      $f0, 0x14($sp)
/* EA3620 80242D20 4600008D */  trunc.w.s $f2, $f0
/* EA3624 80242D24 44061000 */  mfc1      $a2, $f2
/* EA3628 80242D28 0C0B551A */  jal       func_802D5468
/* EA362C 80242D2C 02A0282D */   daddu    $a1, $s5, $zero
/* EA3630 80242D30 8FBF0034 */  lw        $ra, 0x34($sp)
/* EA3634 80242D34 8FB60030 */  lw        $s6, 0x30($sp)
/* EA3638 80242D38 8FB5002C */  lw        $s5, 0x2c($sp)
/* EA363C 80242D3C 8FB40028 */  lw        $s4, 0x28($sp)
/* EA3640 80242D40 8FB30024 */  lw        $s3, 0x24($sp)
/* EA3644 80242D44 8FB20020 */  lw        $s2, 0x20($sp)
/* EA3648 80242D48 8FB1001C */  lw        $s1, 0x1c($sp)
/* EA364C 80242D4C 8FB00018 */  lw        $s0, 0x18($sp)
/* EA3650 80242D50 D7B60040 */  ldc1      $f22, 0x40($sp)
/* EA3654 80242D54 D7B40038 */  ldc1      $f20, 0x38($sp)
/* EA3658 80242D58 24020002 */  addiu     $v0, $zero, 2
/* EA365C 80242D5C 03E00008 */  jr        $ra
/* EA3660 80242D60 27BD0048 */   addiu    $sp, $sp, 0x48
