.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EC0_E06220
/* E06220 80240EC0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* E06224 80240EC4 AFB00048 */  sw        $s0, 0x48($sp)
/* E06228 80240EC8 00A0802D */  daddu     $s0, $a1, $zero
/* E0622C 80240ECC AFBF0050 */  sw        $ra, 0x50($sp)
/* E06230 80240ED0 AFB1004C */  sw        $s1, 0x4c($sp)
/* E06234 80240ED4 F7B80068 */  sdc1      $f24, 0x68($sp)
/* E06238 80240ED8 F7B60060 */  sdc1      $f22, 0x60($sp)
/* E0623C 80240EDC F7B40058 */  sdc1      $f20, 0x58($sp)
/* E06240 80240EE0 8C82001C */  lw        $v0, 0x1c($a0)
/* E06244 80240EE4 0000202D */  daddu     $a0, $zero, $zero
/* E06248 80240EE8 0000282D */  daddu     $a1, $zero, $zero
/* E0624C 80240EEC C6140010 */  lwc1      $f20, 0x10($s0)
/* E06250 80240EF0 4680A520 */  cvt.s.w   $f20, $f20
/* E06254 80240EF4 3C06437F */  lui       $a2, 0x437f
/* E06258 80240EF8 C6160014 */  lwc1      $f22, 0x14($s0)
/* E0625C 80240EFC 4680B5A0 */  cvt.s.w   $f22, $f22
/* E06260 80240F00 AFA20010 */  sw        $v0, 0x10($sp)
/* E06264 80240F04 8E070018 */  lw        $a3, 0x18($s0)
/* E06268 80240F08 0C00A8ED */  jal       update_lerp
/* E0626C 80240F0C 27B10038 */   addiu    $s1, $sp, 0x38
/* E06270 80240F10 AFB10010 */  sw        $s1, 0x10($sp)
/* E06274 80240F14 8E040004 */  lw        $a0, 4($s0)
/* E06278 80240F18 8E050008 */  lw        $a1, 8($s0)
/* E0627C 80240F1C 8E060000 */  lw        $a2, ($s0)
/* E06280 80240F20 8E07000C */  lw        $a3, 0xc($s0)
/* E06284 80240F24 0C04BA38 */  jal       func_8012E8E0
/* E06288 80240F28 46000606 */   mov.s    $f24, $f0
/* E0628C 80240F2C 4600A08D */  trunc.w.s $f2, $f20
/* E06290 80240F30 44021000 */  mfc1      $v0, $f2
/* E06294 80240F34 93A50040 */  lbu       $a1, 0x40($sp)
/* E06298 80240F38 93A60041 */  lbu       $a2, 0x41($sp)
/* E0629C 80240F3C 00021400 */  sll       $v0, $v0, 0x10
/* E062A0 80240F40 AFA00010 */  sw        $zero, 0x10($sp)
/* E062A4 80240F44 8FA3003C */  lw        $v1, 0x3c($sp)
/* E062A8 80240F48 00021403 */  sra       $v0, $v0, 0x10
/* E062AC 80240F4C AFA20018 */  sw        $v0, 0x18($sp)
/* E062B0 80240F50 4600B08D */  trunc.w.s $f2, $f22
/* E062B4 80240F54 44021000 */  mfc1      $v0, $f2
/* E062B8 80240F58 00000000 */  nop       
/* E062BC 80240F5C 00021400 */  sll       $v0, $v0, 0x10
/* E062C0 80240F60 3C014F00 */  lui       $at, 0x4f00
/* E062C4 80240F64 44810000 */  mtc1      $at, $f0
/* E062C8 80240F68 00021403 */  sra       $v0, $v0, 0x10
/* E062CC 80240F6C AFA2001C */  sw        $v0, 0x1c($sp)
/* E062D0 80240F70 2402000A */  addiu     $v0, $zero, 0xa
/* E062D4 80240F74 AFA20020 */  sw        $v0, 0x20($sp)
/* E062D8 80240F78 24020014 */  addiu     $v0, $zero, 0x14
/* E062DC 80240F7C AFA20024 */  sw        $v0, 0x24($sp)
/* E062E0 80240F80 2402012C */  addiu     $v0, $zero, 0x12c
/* E062E4 80240F84 AFA20028 */  sw        $v0, 0x28($sp)
/* E062E8 80240F88 240200C8 */  addiu     $v0, $zero, 0xc8
/* E062EC 80240F8C AFA2002C */  sw        $v0, 0x2c($sp)
/* E062F0 80240F90 4618003E */  c.le.s    $f0, $f24
/* E062F4 80240F94 00000000 */  nop       
/* E062F8 80240F98 45010005 */  bc1t      .L80240FB0
/* E062FC 80240F9C AFA30014 */   sw       $v1, 0x14($sp)
/* E06300 80240FA0 4600C08D */  trunc.w.s $f2, $f24
/* E06304 80240FA4 44031000 */  mfc1      $v1, $f2
/* E06308 80240FA8 080903F3 */  j         .L80240FCC
/* E0630C 80240FAC 306200FF */   andi     $v0, $v1, 0xff
.L80240FB0:
/* E06310 80240FB0 4600C001 */  sub.s     $f0, $f24, $f0
/* E06314 80240FB4 3C028000 */  lui       $v0, 0x8000
/* E06318 80240FB8 4600008D */  trunc.w.s $f2, $f0
/* E0631C 80240FBC 44031000 */  mfc1      $v1, $f2
/* E06320 80240FC0 00000000 */  nop       
/* E06324 80240FC4 00621825 */  or        $v1, $v1, $v0
/* E06328 80240FC8 306200FF */  andi      $v0, $v1, 0xff
.L80240FCC:
/* E0632C 80240FCC AFA20030 */  sw        $v0, 0x30($sp)
/* E06330 80240FD0 8E240000 */  lw        $a0, ($s1)
/* E06334 80240FD4 0C04BA68 */  jal       func_8012E9A0
/* E06338 80240FD8 24070002 */   addiu    $a3, $zero, 2
/* E0633C 80240FDC 8FBF0050 */  lw        $ra, 0x50($sp)
/* E06340 80240FE0 8FB1004C */  lw        $s1, 0x4c($sp)
/* E06344 80240FE4 8FB00048 */  lw        $s0, 0x48($sp)
/* E06348 80240FE8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* E0634C 80240FEC D7B60060 */  ldc1      $f22, 0x60($sp)
/* E06350 80240FF0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* E06354 80240FF4 03E00008 */  jr        $ra
/* E06358 80240FF8 27BD0070 */   addiu    $sp, $sp, 0x70
