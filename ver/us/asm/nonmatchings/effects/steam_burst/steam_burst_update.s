.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_E005C710
.double 0.1

dlabel D_E005C718
.double 0.04

dlabel D_E005C720
.double 0.9, 0.0

.section .text

glabel steam_burst_update
/* 3610C0 E005C180 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3610C4 E005C184 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3610C8 E005C188 8C85000C */  lw        $a1, 0xc($a0)
/* 3610CC E005C18C 3C0140E0 */  lui       $at, 0x40e0
/* 3610D0 E005C190 44810000 */  mtc1      $at, $f0
/* 3610D4 E005C194 8CA20028 */  lw        $v0, 0x28($a1)
/* 3610D8 E005C198 8CA30024 */  lw        $v1, 0x24($a1)
/* 3610DC E005C19C 44821000 */  mtc1      $v0, $f2
/* 3610E0 E005C1A0 00000000 */  nop
/* 3610E4 E005C1A4 468010A0 */  cvt.s.w   $f2, $f2
/* 3610E8 E005C1A8 24420001 */  addiu     $v0, $v0, 1
/* 3610EC E005C1AC 46001082 */  mul.s     $f2, $f2, $f0
/* 3610F0 E005C1B0 00000000 */  nop
/* 3610F4 E005C1B4 2463FFFF */  addiu     $v1, $v1, -1
/* 3610F8 E005C1B8 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* 3610FC E005C1BC 46800020 */  cvt.s.w   $f0, $f0
/* 361100 E005C1C0 ACA20028 */  sw        $v0, 0x28($a1)
/* 361104 E005C1C4 ACA30024 */  sw        $v1, 0x24($a1)
/* 361108 E005C1C8 46001083 */  div.s     $f2, $f2, $f0
/* 36110C E005C1CC 04610005 */  bgez      $v1, .LE005C1E4
/* 361110 E005C1D0 E4A20030 */   swc1     $f2, 0x30($a1)
/* 361114 E005C1D4 0C080128 */  jal       shim_remove_effect
/* 361118 E005C1D8 00000000 */   nop
/* 36111C E005C1DC 080170AA */  j         .LE005C2A8
/* 361120 E005C1E0 00000000 */   nop
.LE005C1E4:
/* 361124 E005C1E4 C4A2001C */  lwc1      $f2, 0x1c($a1)
/* 361128 E005C1E8 C4A00020 */  lwc1      $f0, 0x20($a1)
/* 36112C E005C1EC 46020001 */  sub.s     $f0, $f0, $f2
/* 361130 E005C1F0 3C01E006 */  lui       $at, %hi(D_E005C710)
/* 361134 E005C1F4 D424C710 */  ldc1      $f4, %lo(D_E005C710)($at)
/* 361138 E005C1F8 46000021 */  cvt.d.s   $f0, $f0
/* 36113C E005C1FC 46240002 */  mul.d     $f0, $f0, $f4
/* 361140 E005C200 00000000 */  nop
/* 361144 E005C204 460010A1 */  cvt.d.s   $f2, $f2
/* 361148 E005C208 46201080 */  add.d     $f2, $f2, $f0
/* 36114C E005C20C 24060001 */  addiu     $a2, $zero, 1
/* 361150 E005C210 462010A0 */  cvt.s.d   $f2, $f2
/* 361154 E005C214 E4A2001C */  swc1      $f2, 0x1c($a1)
/* 361158 E005C218 24A50034 */  addiu     $a1, $a1, 0x34
/* 36115C E005C21C 8C820008 */  lw        $v0, 8($a0)
/* 361160 E005C220 00C2102A */  slt       $v0, $a2, $v0
/* 361164 E005C224 10400020 */  beqz      $v0, .LE005C2A8
/* 361168 E005C228 46001206 */   mov.s    $f8, $f2
/* 36116C E005C22C 24A3000C */  addiu     $v1, $a1, 0xc
/* 361170 E005C230 3C01E006 */  lui       $at, %hi(D_E005C718)
/* 361174 E005C234 D42CC718 */  ldc1      $f12, %lo(D_E005C718)($at)
/* 361178 E005C238 3C01E006 */  lui       $at, %hi(D_E005C720)
/* 36117C E005C23C D42AC720 */  ldc1      $f10, %lo(D_E005C720)($at)
.LE005C240:
/* 361180 E005C240 C4600008 */  lwc1      $f0, 8($v1)
/* 361184 E005C244 46000021 */  cvt.d.s   $f0, $f0
/* 361188 E005C248 462C0000 */  add.d     $f0, $f0, $f12
/* 36118C E005C24C 46200020 */  cvt.s.d   $f0, $f0
/* 361190 E005C250 46000021 */  cvt.d.s   $f0, $f0
/* 361194 E005C254 462A0002 */  mul.d     $f0, $f0, $f10
/* 361198 E005C258 00000000 */  nop
/* 36119C E005C25C C4660004 */  lwc1      $f6, 4($v1)
/* 3611A0 E005C260 46064182 */  mul.s     $f6, $f8, $f6
/* 3611A4 E005C264 00000000 */  nop
/* 3611A8 E005C268 C464000C */  lwc1      $f4, 0xc($v1)
/* 3611AC E005C26C 46044102 */  mul.s     $f4, $f8, $f4
/* 3611B0 E005C270 00000000 */  nop
/* 3611B4 E005C274 46200020 */  cvt.s.d   $f0, $f0
/* 3611B8 E005C278 E4600008 */  swc1      $f0, 8($v1)
/* 3611BC E005C27C C460FFFC */  lwc1      $f0, -4($v1)
/* 3611C0 E005C280 C4620008 */  lwc1      $f2, 8($v1)
/* 3611C4 E005C284 24C60001 */  addiu     $a2, $a2, 1
/* 3611C8 E005C288 46020000 */  add.s     $f0, $f0, $f2
/* 3611CC E005C28C E466FFF8 */  swc1      $f6, -8($v1)
/* 3611D0 E005C290 E4640000 */  swc1      $f4, ($v1)
/* 3611D4 E005C294 E460FFFC */  swc1      $f0, -4($v1)
/* 3611D8 E005C298 8C820008 */  lw        $v0, 8($a0)
/* 3611DC E005C29C 00C2102A */  slt       $v0, $a2, $v0
/* 3611E0 E005C2A0 1440FFE7 */  bnez      $v0, .LE005C240
/* 3611E4 E005C2A4 24630034 */   addiu    $v1, $v1, 0x34
.LE005C2A8:
/* 3611E8 E005C2A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3611EC E005C2AC 03E00008 */  jr        $ra
/* 3611F0 E005C2B0 27BD0018 */   addiu    $sp, $sp, 0x18
