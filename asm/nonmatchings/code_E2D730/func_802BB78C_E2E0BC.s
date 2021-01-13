.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB78C_E2E0BC
/* E2E0BC 802BB78C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2E0C0 802BB790 AFB00010 */  sw        $s0, 0x10($sp)
/* E2E0C4 802BB794 0080802D */  daddu     $s0, $a0, $zero
/* E2E0C8 802BB798 AFBF0018 */  sw        $ra, 0x18($sp)
/* E2E0CC 802BB79C AFB10014 */  sw        $s1, 0x14($sp)
/* E2E0D0 802BB7A0 8E110040 */  lw        $s1, 0x40($s0)
/* E2E0D4 802BB7A4 96230002 */  lhu       $v1, 2($s1)
/* E2E0D8 802BB7A8 10600005 */  beqz      $v1, .L802BB7C0
/* E2E0DC 802BB7AC 24020001 */   addiu    $v0, $zero, 1
/* E2E0E0 802BB7B0 10620014 */  beq       $v1, $v0, .L802BB804
/* E2E0E4 802BB7B4 00000000 */   nop
/* E2E0E8 802BB7B8 080AEE29 */  j         .L802BB8A4
/* E2E0EC 802BB7BC 00000000 */   nop
.L802BB7C0:
/* E2E0F0 802BB7C0 96220000 */  lhu       $v0, ($s1)
/* E2E0F4 802BB7C4 10400037 */  beqz      $v0, .L802BB8A4
/* E2E0F8 802BB7C8 00000000 */   nop
/* E2E0FC 802BB7CC 96220002 */  lhu       $v0, 2($s1)
/* E2E100 802BB7D0 3C01C1C8 */  lui       $at, 0xc1c8
/* E2E104 802BB7D4 44810000 */  mtc1      $at, $f0
/* E2E108 802BB7D8 3C013FE6 */  lui       $at, 0x3fe6
/* E2E10C 802BB7DC 34216666 */  ori       $at, $at, 0x6666
/* E2E110 802BB7E0 44811000 */  mtc1      $at, $f2
/* E2E114 802BB7E4 A6200000 */  sh        $zero, ($s1)
/* E2E118 802BB7E8 24420001 */  addiu     $v0, $v0, 1
/* E2E11C 802BB7EC A6220002 */  sh        $v0, 2($s1)
/* E2E120 802BB7F0 240200FF */  addiu     $v0, $zero, 0xff
/* E2E124 802BB7F4 E6000068 */  swc1      $f0, 0x68($s0)
/* E2E128 802BB7F8 E6020054 */  swc1      $f2, 0x54($s0)
/* E2E12C 802BB7FC 080AEE29 */  j         .L802BB8A4
/* E2E130 802BB800 A202000B */   sb       $v0, 0xb($s0)
.L802BB804:
/* E2E134 802BB804 C6000068 */  lwc1      $f0, 0x68($s0)
/* E2E138 802BB808 3C013F80 */  lui       $at, 0x3f80
/* E2E13C 802BB80C 44811000 */  mtc1      $at, $f2
/* E2E140 802BB810 00000000 */  nop
/* E2E144 802BB814 46020000 */  add.s     $f0, $f0, $f2
/* E2E148 802BB818 3C014100 */  lui       $at, 0x4100
/* E2E14C 802BB81C 44811000 */  mtc1      $at, $f2
/* E2E150 802BB820 00000000 */  nop
/* E2E154 802BB824 4600103E */  c.le.s    $f2, $f0
/* E2E158 802BB828 00000000 */  nop
/* E2E15C 802BB82C 45000002 */  bc1f      .L802BB838
/* E2E160 802BB830 E6000068 */   swc1     $f0, 0x68($s0)
/* E2E164 802BB834 E6020068 */  swc1      $f2, 0x68($s0)
.L802BB838:
/* E2E168 802BB838 9202000B */  lbu       $v0, 0xb($s0)
/* E2E16C 802BB83C 2442FFFA */  addiu     $v0, $v0, -6
/* E2E170 802BB840 A202000B */  sb        $v0, 0xb($s0)
/* E2E174 802BB844 304200FF */  andi      $v0, $v0, 0xff
/* E2E178 802BB848 2C420006 */  sltiu     $v0, $v0, 6
/* E2E17C 802BB84C 10400002 */  beqz      $v0, .L802BB858
/* E2E180 802BB850 24020006 */   addiu    $v0, $zero, 6
/* E2E184 802BB854 A202000B */  sb        $v0, 0xb($s0)
.L802BB858:
/* E2E188 802BB858 C6000054 */  lwc1      $f0, 0x54($s0)
/* E2E18C 802BB85C 3C01802C */  lui       $at, %hi(D_802BCDD8)
/* E2E190 802BB860 D422CDD8 */  ldc1      $f2, %lo(D_802BCDD8)($at)
/* E2E194 802BB864 46000021 */  cvt.d.s   $f0, $f0
/* E2E198 802BB868 46220001 */  sub.d     $f0, $f0, $f2
/* E2E19C 802BB86C 3C01802C */  lui       $at, %hi(D_802BCDE0)
/* E2E1A0 802BB870 D424CDE0 */  ldc1      $f4, %lo(D_802BCDE0)($at)
/* E2E1A4 802BB874 46200020 */  cvt.s.d   $f0, $f0
/* E2E1A8 802BB878 460000A1 */  cvt.d.s   $f2, $f0
/* E2E1AC 802BB87C 4624103E */  c.le.d    $f2, $f4
/* E2E1B0 802BB880 00000000 */  nop
/* E2E1B4 802BB884 45000003 */  bc1f      .L802BB894
/* E2E1B8 802BB888 E6000054 */   swc1     $f0, 0x54($s0)
/* E2E1BC 802BB88C A6200002 */  sh        $zero, 2($s1)
/* E2E1C0 802BB890 AE000054 */  sw        $zero, 0x54($s0)
.L802BB894:
/* E2E1C4 802BB894 C6000054 */  lwc1      $f0, 0x54($s0)
/* E2E1C8 802BB898 46000086 */  mov.s     $f2, $f0
/* E2E1CC 802BB89C E6000058 */  swc1      $f0, 0x58($s0)
/* E2E1D0 802BB8A0 E602005C */  swc1      $f2, 0x5c($s0)
.L802BB8A4:
/* E2E1D4 802BB8A4 0C04417A */  jal       get_entity_by_index
/* E2E1D8 802BB8A8 96240004 */   lhu      $a0, 4($s1)
/* E2E1DC 802BB8AC C4400064 */  lwc1      $f0, 0x64($v0)
/* E2E1E0 802BB8B0 E6200008 */  swc1      $f0, 8($s1)
/* E2E1E4 802BB8B4 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* E2E1E8 802BB8B8 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* E2E1EC 802BB8BC E6000064 */  swc1      $f0, 0x64($s0)
/* E2E1F0 802BB8C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* E2E1F4 802BB8C4 8FB10014 */  lw        $s1, 0x14($sp)
/* E2E1F8 802BB8C8 8FB00010 */  lw        $s0, 0x10($sp)
/* E2E1FC 802BB8CC 03E00008 */  jr        $ra
/* E2E200 802BB8D0 27BD0020 */   addiu    $sp, $sp, 0x20
