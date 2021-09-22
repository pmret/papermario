.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B94_EE0554
/* EE0554 80241B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* EE0558 80241B98 AFB20048 */  sw        $s2, 0x48($sp)
/* EE055C 80241B9C 0080902D */  daddu     $s2, $a0, $zero
/* EE0560 80241BA0 AFBF0054 */  sw        $ra, 0x54($sp)
/* EE0564 80241BA4 AFB40050 */  sw        $s4, 0x50($sp)
/* EE0568 80241BA8 AFB3004C */  sw        $s3, 0x4c($sp)
/* EE056C 80241BAC AFB10044 */  sw        $s1, 0x44($sp)
/* EE0570 80241BB0 AFB00040 */  sw        $s0, 0x40($sp)
/* EE0574 80241BB4 F7B60060 */  sdc1      $f22, 0x60($sp)
/* EE0578 80241BB8 F7B40058 */  sdc1      $f20, 0x58($sp)
/* EE057C 80241BBC 8E510148 */  lw        $s1, 0x148($s2)
/* EE0580 80241BC0 00A0982D */  daddu     $s3, $a1, $zero
/* EE0584 80241BC4 86240008 */  lh        $a0, 8($s1)
/* EE0588 80241BC8 0C00F92F */  jal       dead_get_npc_unsafe
/* EE058C 80241BCC 00C0A02D */   daddu    $s4, $a2, $zero
/* EE0590 80241BD0 0040802D */  daddu     $s0, $v0, $zero
/* EE0594 80241BD4 C6200078 */  lwc1      $f0, 0x78($s1)
/* EE0598 80241BD8 46800020 */  cvt.s.w   $f0, $f0
/* EE059C 80241BDC 46000021 */  cvt.d.s   $f0, $f0
/* EE05A0 80241BE0 3C014059 */  lui       $at, 0x4059
/* EE05A4 80241BE4 44814800 */  mtc1      $at, $f9
/* EE05A8 80241BE8 44804000 */  mtc1      $zero, $f8
/* EE05AC 80241BEC 8602008E */  lh        $v0, 0x8e($s0)
/* EE05B0 80241BF0 9603008E */  lhu       $v1, 0x8e($s0)
/* EE05B4 80241BF4 46280003 */  div.d     $f0, $f0, $f8
/* EE05B8 80241BF8 18400003 */  blez      $v0, .L80241C08
/* EE05BC 80241BFC 462005A0 */   cvt.s.d  $f22, $f0
/* EE05C0 80241C00 2462FFFF */  addiu     $v0, $v1, -1
/* EE05C4 80241C04 A602008E */  sh        $v0, 0x8e($s0)
.L80241C08:
/* EE05C8 80241C08 27A50028 */  addiu     $a1, $sp, 0x28
/* EE05CC 80241C0C 27A6002C */  addiu     $a2, $sp, 0x2c
/* EE05D0 80241C10 27A70030 */  addiu     $a3, $sp, 0x30
/* EE05D4 80241C14 C6000038 */  lwc1      $f0, 0x38($s0)
/* EE05D8 80241C18 C602003C */  lwc1      $f2, 0x3c($s0)
/* EE05DC 80241C1C C6040040 */  lwc1      $f4, 0x40($s0)
/* EE05E0 80241C20 3C01447A */  lui       $at, 0x447a
/* EE05E4 80241C24 44813000 */  mtc1      $at, $f6
/* EE05E8 80241C28 27A20034 */  addiu     $v0, $sp, 0x34
/* EE05EC 80241C2C E7A00028 */  swc1      $f0, 0x28($sp)
/* EE05F0 80241C30 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EE05F4 80241C34 E7A40030 */  swc1      $f4, 0x30($sp)
/* EE05F8 80241C38 E7A60034 */  swc1      $f6, 0x34($sp)
/* EE05FC 80241C3C C6340070 */  lwc1      $f20, 0x70($s1)
/* EE0600 80241C40 4680A520 */  cvt.s.w   $f20, $f20
/* EE0604 80241C44 4600A521 */  cvt.d.s   $f20, $f20
/* EE0608 80241C48 4628A503 */  div.d     $f20, $f20, $f8
/* EE060C 80241C4C AFA20010 */  sw        $v0, 0x10($sp)
/* EE0610 80241C50 8E040080 */  lw        $a0, 0x80($s0)
/* EE0614 80241C54 0C03908F */  jal       dead_npc_raycast_down_sides
/* EE0618 80241C58 4620A520 */   cvt.s.d  $f20, $f20
/* EE061C 80241C5C C62C0074 */  lwc1      $f12, 0x74($s1)
/* EE0620 80241C60 0C00AD77 */  jal       dead_sin_deg
/* EE0624 80241C64 46806320 */   cvt.s.w  $f12, $f12
/* EE0628 80241C68 46140002 */  mul.s     $f0, $f0, $f20
/* EE062C 80241C6C 00000000 */  nop
/* EE0630 80241C70 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* EE0634 80241C74 46161080 */  add.s     $f2, $f2, $f22
/* EE0638 80241C78 46001080 */  add.s     $f2, $f2, $f0
/* EE063C 80241C7C E602003C */  swc1      $f2, 0x3c($s0)
/* EE0640 80241C80 8E220074 */  lw        $v0, 0x74($s1)
/* EE0644 80241C84 2442000C */  addiu     $v0, $v0, 0xc
/* EE0648 80241C88 44826000 */  mtc1      $v0, $f12
/* EE064C 80241C8C 00000000 */  nop
/* EE0650 80241C90 0C00AB85 */  jal       dead_clamp_angle
/* EE0654 80241C94 46806320 */   cvt.s.w  $f12, $f12
/* EE0658 80241C98 4600028D */  trunc.w.s $f10, $f0
/* EE065C 80241C9C E62A0074 */  swc1      $f10, 0x74($s1)
/* EE0660 80241CA0 0280202D */  daddu     $a0, $s4, $zero
/* EE0664 80241CA4 24020001 */  addiu     $v0, $zero, 1
/* EE0668 80241CA8 AFA20010 */  sw        $v0, 0x10($sp)
/* EE066C 80241CAC 8E660024 */  lw        $a2, 0x24($s3)
/* EE0670 80241CB0 8E670028 */  lw        $a3, 0x28($s3)
/* EE0674 80241CB4 0C013469 */  jal       func_8004D1A4
/* EE0678 80241CB8 0220282D */   daddu    $a1, $s1, $zero
/* EE067C 80241CBC 1040001D */  beqz      $v0, .L80241D34
/* EE0680 80241CC0 0000202D */   daddu    $a0, $zero, $zero
/* EE0684 80241CC4 0200282D */  daddu     $a1, $s0, $zero
/* EE0688 80241CC8 0000302D */  daddu     $a2, $zero, $zero
/* EE068C 80241CCC 860300A8 */  lh        $v1, 0xa8($s0)
/* EE0690 80241CD0 3C013F80 */  lui       $at, 0x3f80
/* EE0694 80241CD4 44810000 */  mtc1      $at, $f0
/* EE0698 80241CD8 3C014000 */  lui       $at, 0x4000
/* EE069C 80241CDC 44811000 */  mtc1      $at, $f2
/* EE06A0 80241CE0 3C01C1A0 */  lui       $at, 0xc1a0
/* EE06A4 80241CE4 44812000 */  mtc1      $at, $f4
/* EE06A8 80241CE8 2402000F */  addiu     $v0, $zero, 0xf
/* EE06AC 80241CEC AFA2001C */  sw        $v0, 0x1c($sp)
/* EE06B0 80241CF0 44835000 */  mtc1      $v1, $f10
/* EE06B4 80241CF4 00000000 */  nop
/* EE06B8 80241CF8 468052A0 */  cvt.s.w   $f10, $f10
/* EE06BC 80241CFC 44075000 */  mfc1      $a3, $f10
/* EE06C0 80241D00 27A20038 */  addiu     $v0, $sp, 0x38
/* EE06C4 80241D04 AFA20020 */  sw        $v0, 0x20($sp)
/* EE06C8 80241D08 E7A00010 */  swc1      $f0, 0x10($sp)
/* EE06CC 80241D0C E7A20014 */  swc1      $f2, 0x14($sp)
/* EE06D0 80241D10 0C01D444 */  jal       dead_fx_emote
/* EE06D4 80241D14 E7A40018 */   swc1     $f4, 0x18($sp)
/* EE06D8 80241D18 0200202D */  daddu     $a0, $s0, $zero
/* EE06DC 80241D1C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EE06E0 80241D20 0C013600 */  jal       dead_ai_enemy_play_sound
/* EE06E4 80241D24 3C060020 */   lui      $a2, 0x20
/* EE06E8 80241D28 2402000C */  addiu     $v0, $zero, 0xc
/* EE06EC 80241D2C 0809076F */  j         .L80241DBC
/* EE06F0 80241D30 AE420070 */   sw       $v0, 0x70($s2)
.L80241D34:
/* EE06F4 80241D34 8602008C */  lh        $v0, 0x8c($s0)
/* EE06F8 80241D38 14400020 */  bnez      $v0, .L80241DBC
/* EE06FC 80241D3C 00000000 */   nop
/* EE0700 80241D40 8602008E */  lh        $v0, 0x8e($s0)
/* EE0704 80241D44 1C40001D */  bgtz      $v0, .L80241DBC
/* EE0708 80241D48 00000000 */   nop
/* EE070C 80241D4C 8E420074 */  lw        $v0, 0x74($s2)
/* EE0710 80241D50 2442FFFF */  addiu     $v0, $v0, -1
/* EE0714 80241D54 18400018 */  blez      $v0, .L80241DB8
/* EE0718 80241D58 AE420074 */   sw       $v0, 0x74($s2)
/* EE071C 80241D5C C600000C */  lwc1      $f0, 0xc($s0)
/* EE0720 80241D60 3C014334 */  lui       $at, 0x4334
/* EE0724 80241D64 44816000 */  mtc1      $at, $f12
/* EE0728 80241D68 0C00AB85 */  jal       dead_clamp_angle
/* EE072C 80241D6C 460C0300 */   add.s    $f12, $f0, $f12
/* EE0730 80241D70 240403E8 */  addiu     $a0, $zero, 0x3e8
/* EE0734 80241D74 0C00AB3B */  jal       dead_rand_int
/* EE0738 80241D78 E600000C */   swc1     $f0, 0xc($s0)
/* EE073C 80241D7C 3C032E8B */  lui       $v1, 0x2e8b
/* EE0740 80241D80 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* EE0744 80241D84 00430018 */  mult      $v0, $v1
/* EE0748 80241D88 00021FC3 */  sra       $v1, $v0, 0x1f
/* EE074C 80241D8C 00004010 */  mfhi      $t0
/* EE0750 80241D90 00082043 */  sra       $a0, $t0, 1
/* EE0754 80241D94 00832023 */  subu      $a0, $a0, $v1
/* EE0758 80241D98 00041840 */  sll       $v1, $a0, 1
/* EE075C 80241D9C 00641821 */  addu      $v1, $v1, $a0
/* EE0760 80241DA0 00031880 */  sll       $v1, $v1, 2
/* EE0764 80241DA4 00641823 */  subu      $v1, $v1, $a0
/* EE0768 80241DA8 00431023 */  subu      $v0, $v0, $v1
/* EE076C 80241DAC 24420005 */  addiu     $v0, $v0, 5
/* EE0770 80241DB0 0809076F */  j         .L80241DBC
/* EE0774 80241DB4 A602008E */   sh       $v0, 0x8e($s0)
.L80241DB8:
/* EE0778 80241DB8 AE400070 */  sw        $zero, 0x70($s2)
.L80241DBC:
/* EE077C 80241DBC 8FBF0054 */  lw        $ra, 0x54($sp)
/* EE0780 80241DC0 8FB40050 */  lw        $s4, 0x50($sp)
/* EE0784 80241DC4 8FB3004C */  lw        $s3, 0x4c($sp)
/* EE0788 80241DC8 8FB20048 */  lw        $s2, 0x48($sp)
/* EE078C 80241DCC 8FB10044 */  lw        $s1, 0x44($sp)
/* EE0790 80241DD0 8FB00040 */  lw        $s0, 0x40($sp)
/* EE0794 80241DD4 D7B60060 */  ldc1      $f22, 0x60($sp)
/* EE0798 80241DD8 D7B40058 */  ldc1      $f20, 0x58($sp)
/* EE079C 80241DDC 03E00008 */  jr        $ra
/* EE07A0 80241DE0 27BD0068 */   addiu    $sp, $sp, 0x68
