.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_80218000_4F7BE0
/* 4F7BE0 80218000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4F7BE4 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7BE8 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 4F7BEC 8021800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4F7BF0 80218010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7BF4 80218014 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7BF8 80218018 AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7BFC 8021801C 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7C00 80218020 8E050000 */  lw        $a1, ($s0)
/* 4F7C04 80218024 0C0B1EAF */  jal       get_variable
/* 4F7C08 80218028 26100004 */   addiu    $s0, $s0, 4
/* 4F7C0C 8021802C 8E050000 */  lw        $a1, ($s0)
/* 4F7C10 80218030 26100004 */  addiu     $s0, $s0, 4
/* 4F7C14 80218034 0220202D */  daddu     $a0, $s1, $zero
/* 4F7C18 80218038 0C0B1EAF */  jal       get_variable
/* 4F7C1C 8021803C 0040982D */   daddu    $s3, $v0, $zero
/* 4F7C20 80218040 8E050000 */  lw        $a1, ($s0)
/* 4F7C24 80218044 26100004 */  addiu     $s0, $s0, 4
/* 4F7C28 80218048 0220202D */  daddu     $a0, $s1, $zero
/* 4F7C2C 8021804C 0C0B1EAF */  jal       get_variable
/* 4F7C30 80218050 0040902D */   daddu    $s2, $v0, $zero
/* 4F7C34 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 4F7C38 80218058 8E050000 */  lw        $a1, ($s0)
/* 4F7C3C 8021805C 0C0B1EAF */  jal       get_variable
/* 4F7C40 80218060 0040802D */   daddu    $s0, $v0, $zero
/* 4F7C44 80218064 44936000 */  mtc1      $s3, $f12
/* 4F7C48 80218068 00000000 */  nop       
/* 4F7C4C 8021806C 46806320 */  cvt.s.w   $f12, $f12
/* 4F7C50 80218070 44927000 */  mtc1      $s2, $f14
/* 4F7C54 80218074 00000000 */  nop       
/* 4F7C58 80218078 468073A0 */  cvt.s.w   $f14, $f14
/* 4F7C5C 8021807C 44900000 */  mtc1      $s0, $f0
/* 4F7C60 80218080 00000000 */  nop       
/* 4F7C64 80218084 46800020 */  cvt.s.w   $f0, $f0
/* 4F7C68 80218088 44060000 */  mfc1      $a2, $f0
/* 4F7C6C 8021808C 0C0B5D18 */  jal       func_802D7460
/* 4F7C70 80218090 0040382D */   daddu    $a3, $v0, $zero
/* 4F7C74 80218094 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4F7C78 80218098 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7C7C 8021809C 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7C80 802180A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7C84 802180A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7C88 802180A8 24020002 */  addiu     $v0, $zero, 2
/* 4F7C8C 802180AC 03E00008 */  jr        $ra
/* 4F7C90 802180B0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4F7C94 802180B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4F7C98 802180B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7C9C 802180BC 0080882D */  daddu     $s1, $a0, $zero
/* 4F7CA0 802180C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4F7CA4 802180C4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7CA8 802180C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7CAC 802180CC AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7CB0 802180D0 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7CB4 802180D4 8E050000 */  lw        $a1, ($s0)
/* 4F7CB8 802180D8 0C0B1EAF */  jal       get_variable
/* 4F7CBC 802180DC 26100004 */   addiu    $s0, $s0, 4
/* 4F7CC0 802180E0 8E050000 */  lw        $a1, ($s0)
/* 4F7CC4 802180E4 26100004 */  addiu     $s0, $s0, 4
/* 4F7CC8 802180E8 0220202D */  daddu     $a0, $s1, $zero
/* 4F7CCC 802180EC 0C0B1EAF */  jal       get_variable
/* 4F7CD0 802180F0 0040982D */   daddu    $s3, $v0, $zero
/* 4F7CD4 802180F4 8E050000 */  lw        $a1, ($s0)
/* 4F7CD8 802180F8 26100004 */  addiu     $s0, $s0, 4
/* 4F7CDC 802180FC 0220202D */  daddu     $a0, $s1, $zero
/* 4F7CE0 80218100 0C0B1EAF */  jal       get_variable
/* 4F7CE4 80218104 0040902D */   daddu    $s2, $v0, $zero
/* 4F7CE8 80218108 0220202D */  daddu     $a0, $s1, $zero
/* 4F7CEC 8021810C 8E050000 */  lw        $a1, ($s0)
/* 4F7CF0 80218110 0C0B1EAF */  jal       get_variable
/* 4F7CF4 80218114 0040802D */   daddu    $s0, $v0, $zero
/* 4F7CF8 80218118 44936000 */  mtc1      $s3, $f12
/* 4F7CFC 8021811C 00000000 */  nop       
/* 4F7D00 80218120 46806320 */  cvt.s.w   $f12, $f12
/* 4F7D04 80218124 44927000 */  mtc1      $s2, $f14
/* 4F7D08 80218128 00000000 */  nop       
/* 4F7D0C 8021812C 468073A0 */  cvt.s.w   $f14, $f14
/* 4F7D10 80218130 44900000 */  mtc1      $s0, $f0
/* 4F7D14 80218134 00000000 */  nop       
/* 4F7D18 80218138 46800020 */  cvt.s.w   $f0, $f0
/* 4F7D1C 8021813C 44060000 */  mfc1      $a2, $f0
/* 4F7D20 80218140 0C0B5D30 */  jal       func_802D74C0
/* 4F7D24 80218144 0040382D */   daddu    $a3, $v0, $zero
/* 4F7D28 80218148 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4F7D2C 8021814C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7D30 80218150 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7D34 80218154 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7D38 80218158 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7D3C 8021815C 24020002 */  addiu     $v0, $zero, 2
/* 4F7D40 80218160 03E00008 */  jr        $ra
/* 4F7D44 80218164 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4F7D48 80218168 00000000 */  nop       
/* 4F7D4C 8021816C 00000000 */  nop       
/* 4F7D50 80218170 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4F7D54 80218174 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7D58 80218178 0080882D */  daddu     $s1, $a0, $zero
/* 4F7D5C 8021817C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4F7D60 80218180 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7D64 80218184 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7D68 80218188 AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7D6C 8021818C 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7D70 80218190 8E050000 */  lw        $a1, ($s0)
/* 4F7D74 80218194 0C0B1EAF */  jal       get_variable
/* 4F7D78 80218198 26100004 */   addiu    $s0, $s0, 4
/* 4F7D7C 8021819C 8E050000 */  lw        $a1, ($s0)
/* 4F7D80 802181A0 26100004 */  addiu     $s0, $s0, 4
/* 4F7D84 802181A4 0220202D */  daddu     $a0, $s1, $zero
/* 4F7D88 802181A8 0C0B1EAF */  jal       get_variable
/* 4F7D8C 802181AC 0040982D */   daddu    $s3, $v0, $zero
/* 4F7D90 802181B0 8E050000 */  lw        $a1, ($s0)
/* 4F7D94 802181B4 26100004 */  addiu     $s0, $s0, 4
/* 4F7D98 802181B8 0220202D */  daddu     $a0, $s1, $zero
/* 4F7D9C 802181BC 0C0B1EAF */  jal       get_variable
/* 4F7DA0 802181C0 0040902D */   daddu    $s2, $v0, $zero
/* 4F7DA4 802181C4 0220202D */  daddu     $a0, $s1, $zero
/* 4F7DA8 802181C8 8E050000 */  lw        $a1, ($s0)
/* 4F7DAC 802181CC 0C0B1EAF */  jal       get_variable
/* 4F7DB0 802181D0 0040802D */   daddu    $s0, $v0, $zero
/* 4F7DB4 802181D4 8E240148 */  lw        $a0, 0x148($s1)
/* 4F7DB8 802181D8 0C09A75B */  jal       get_actor
/* 4F7DBC 802181DC 0040882D */   daddu    $s1, $v0, $zero
/* 4F7DC0 802181E0 0040182D */  daddu     $v1, $v0, $zero
/* 4F7DC4 802181E4 8C620008 */  lw        $v0, 8($v1)
/* 4F7DC8 802181E8 90420024 */  lbu       $v0, 0x24($v0)
/* 4F7DCC 802181EC 8C640008 */  lw        $a0, 8($v1)
/* 4F7DD0 802181F0 02629823 */  subu      $s3, $s3, $v0
/* 4F7DD4 802181F4 A0730194 */  sb        $s3, 0x194($v1)
/* 4F7DD8 802181F8 90820025 */  lbu       $v0, 0x25($a0)
/* 4F7DDC 802181FC 02429023 */  subu      $s2, $s2, $v0
/* 4F7DE0 80218200 A0720195 */  sb        $s2, 0x195($v1)
/* 4F7DE4 80218204 90820026 */  lbu       $v0, 0x26($a0)
/* 4F7DE8 80218208 02028023 */  subu      $s0, $s0, $v0
/* 4F7DEC 8021820C A0700196 */  sb        $s0, 0x196($v1)
/* 4F7DF0 80218210 90840027 */  lbu       $a0, 0x27($a0)
/* 4F7DF4 80218214 02248823 */  subu      $s1, $s1, $a0
/* 4F7DF8 80218218 A0710197 */  sb        $s1, 0x197($v1)
/* 4F7DFC 8021821C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4F7E00 80218220 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7E04 80218224 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7E08 80218228 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7E0C 8021822C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7E10 80218230 24020002 */  addiu     $v0, $zero, 2
/* 4F7E14 80218234 03E00008 */  jr        $ra
/* 4F7E18 80218238 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4F7E1C 8021823C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 4F7E20 80218240 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7E24 80218244 0080882D */  daddu     $s1, $a0, $zero
/* 4F7E28 80218248 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4F7E2C 8021824C AFB40020 */  sw        $s4, 0x20($sp)
/* 4F7E30 80218250 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7E34 80218254 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7E38 80218258 AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7E3C 8021825C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 4F7E40 80218260 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 4F7E44 80218264 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7E48 80218268 8E050000 */  lw        $a1, ($s0)
/* 4F7E4C 8021826C 0C0B1EAF */  jal       get_variable
/* 4F7E50 80218270 26100004 */   addiu    $s0, $s0, 4
/* 4F7E54 80218274 8E050000 */  lw        $a1, ($s0)
/* 4F7E58 80218278 26100004 */  addiu     $s0, $s0, 4
/* 4F7E5C 8021827C 0220202D */  daddu     $a0, $s1, $zero
/* 4F7E60 80218280 0C0B1EAF */  jal       get_variable
/* 4F7E64 80218284 0040982D */   daddu    $s3, $v0, $zero
/* 4F7E68 80218288 8E050000 */  lw        $a1, ($s0)
/* 4F7E6C 8021828C 26100004 */  addiu     $s0, $s0, 4
/* 4F7E70 80218290 0220202D */  daddu     $a0, $s1, $zero
/* 4F7E74 80218294 0C0B1EAF */  jal       get_variable
/* 4F7E78 80218298 0040A02D */   daddu    $s4, $v0, $zero
/* 4F7E7C 8021829C 0220202D */  daddu     $a0, $s1, $zero
/* 4F7E80 802182A0 8E050000 */  lw        $a1, ($s0)
/* 4F7E84 802182A4 0C0B1EAF */  jal       get_variable
/* 4F7E88 802182A8 0040902D */   daddu    $s2, $v0, $zero
/* 4F7E8C 802182AC 4482A000 */  mtc1      $v0, $f20
/* 4F7E90 802182B0 00000000 */  nop       
/* 4F7E94 802182B4 4680A520 */  cvt.s.w   $f20, $f20
/* 4F7E98 802182B8 0C00A8D4 */  jal       cos_deg
/* 4F7E9C 802182BC 4600A306 */   mov.s    $f12, $f20
/* 4F7EA0 802182C0 4492B000 */  mtc1      $s2, $f22
/* 4F7EA4 802182C4 00000000 */  nop       
/* 4F7EA8 802182C8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 4F7EAC 802182CC 4600B002 */  mul.s     $f0, $f22, $f0
/* 4F7EB0 802182D0 00000000 */  nop       
/* 4F7EB4 802182D4 4600A306 */  mov.s     $f12, $f20
/* 4F7EB8 802182D8 4493A000 */  mtc1      $s3, $f20
/* 4F7EBC 802182DC 00000000 */  nop       
/* 4F7EC0 802182E0 4680A520 */  cvt.s.w   $f20, $f20
/* 4F7EC4 802182E4 4600A500 */  add.s     $f20, $f20, $f0
/* 4F7EC8 802182E8 0C00A8BB */  jal       sin_deg
/* 4F7ECC 802182EC 26100004 */   addiu    $s0, $s0, 4
/* 4F7ED0 802182F0 4600B582 */  mul.s     $f22, $f22, $f0
/* 4F7ED4 802182F4 00000000 */  nop       
/* 4F7ED8 802182F8 8E050000 */  lw        $a1, ($s0)
/* 4F7EDC 802182FC 26100004 */  addiu     $s0, $s0, 4
/* 4F7EE0 80218300 0220202D */  daddu     $a0, $s1, $zero
/* 4F7EE4 80218304 4406A000 */  mfc1      $a2, $f20
/* 4F7EE8 80218308 4494A000 */  mtc1      $s4, $f20
/* 4F7EEC 8021830C 00000000 */  nop       
/* 4F7EF0 80218310 4680A520 */  cvt.s.w   $f20, $f20
/* 4F7EF4 80218314 0C0B2190 */  jal       set_float_variable
/* 4F7EF8 80218318 4616A501 */   sub.s    $f20, $f20, $f22
/* 4F7EFC 8021831C 8E050000 */  lw        $a1, ($s0)
/* 4F7F00 80218320 4406A000 */  mfc1      $a2, $f20
/* 4F7F04 80218324 0C0B2190 */  jal       set_float_variable
/* 4F7F08 80218328 0220202D */   daddu    $a0, $s1, $zero
/* 4F7F0C 8021832C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4F7F10 80218330 8FB40020 */  lw        $s4, 0x20($sp)
/* 4F7F14 80218334 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7F18 80218338 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7F1C 8021833C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7F20 80218340 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7F24 80218344 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 4F7F28 80218348 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 4F7F2C 8021834C 24020002 */  addiu     $v0, $zero, 2
/* 4F7F30 80218350 03E00008 */  jr        $ra
/* 4F7F34 80218354 27BD0038 */   addiu    $sp, $sp, 0x38
/* 4F7F38 80218358 00000000 */  nop       
/* 4F7F3C 8021835C 00000000 */  nop       
/* 4F7F40 80218360 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4F7F44 80218364 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4F7F48 80218368 0C046ED4 */  jal       enable_world_fog
/* 4F7F4C 8021836C 00000000 */   nop      
/* 4F7F50 80218370 240403B6 */  addiu     $a0, $zero, 0x3b6
/* 4F7F54 80218374 0C046EDD */  jal       set_world_fog_dist
/* 4F7F58 80218378 240503E8 */   addiu    $a1, $zero, 0x3e8
/* 4F7F5C 8021837C 24040010 */  addiu     $a0, $zero, 0x10
/* 4F7F60 80218380 0080282D */  daddu     $a1, $a0, $zero
/* 4F7F64 80218384 0080302D */  daddu     $a2, $a0, $zero
/* 4F7F68 80218388 0C046EE2 */  jal       set_world_fog_color
/* 4F7F6C 8021838C 240700FF */   addiu    $a3, $zero, 0xff
/* 4F7F70 80218390 3C02800B */  lui       $v0, %hi(gCameras)
/* 4F7F74 80218394 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 4F7F78 80218398 24030014 */  addiu     $v1, $zero, 0x14
/* 4F7F7C 8021839C A4430584 */  sh        $v1, 0x584($v0)
/* 4F7F80 802183A0 A4430586 */  sh        $v1, 0x586($v0)
/* 4F7F84 802183A4 2403001C */  addiu     $v1, $zero, 0x1c
/* 4F7F88 802183A8 A4430588 */  sh        $v1, 0x588($v0)
/* 4F7F8C 802183AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4F7F90 802183B0 24020002 */  addiu     $v0, $zero, 2
/* 4F7F94 802183B4 03E00008 */  jr        $ra
/* 4F7F98 802183B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4F7F9C 802183BC 00000000 */  nop       
/* 4F7FA0 802183C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7FA4 802183C4 00000000 */  nop       
/* 4F7FA8 802183C8 00000000 */  nop       
/* 4F7FAC 802183CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F7FB0 802183D0 00000000 */  nop       
/* 4F7FB4 802183D4 00000002 */  srl       $zero, $zero, 0
/* 4F7FB8 802183D8 00000000 */  nop       
/* 4F7FBC 802183DC 00000006 */  srlv      $zero, $zero, $zero
/* 4F7FC0 802183E0 0000005F */  .byte     0x00, 0x00, 0x00, 0x5f
/* 4F7FC4 802183E4 00000009 */  jr        $zero
/* 4F7FC8 802183E8 0000005A */   .byte    0x00, 0x00, 0x00, 0x5a
/* 4F7FCC 802183EC 00000007 */  srav      $zero, $zero, $zero
/* 4F7FD0 802183F0 00000000 */  nop       
/* 4F7FD4 802183F4 00000004 */  sllv      $zero, $zero, $zero
/* 4F7FD8 802183F8 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4F7FDC 802183FC 00000003 */  sra       $zero, $zero, 0
/* 4F7FE0 80218400 00000000 */  nop       
/* 4F7FE4 80218404 0000000B */  movn      $zero, $zero, $zero
/* 4F7FE8 80218408 00000046 */  rotrv     $zero, $zero, $zero
/* 4F7FEC 8021840C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F7FF0 80218410 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 4F7FF4 80218414 0000000A */  movz      $zero, $zero, $zero
/* 4F7FF8 80218418 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 4F7FFC 8021841C 00000008 */  jr        $zero
/* 4F8000 80218420 0000005A */   .byte    0x00, 0x00, 0x00, 0x5a
/* 4F8004 80218424 0000001F */  ddivu     $zero, $zero, $zero
/* 4F8008 80218428 00000000 */  nop       
/* 4F800C 8021842C 00000020 */  add       $zero, $zero, $zero
/* 4F8010 80218430 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F8014 80218434 00000025 */  or        $zero, $zero, $zero
/* 4F8018 80218438 00000000 */  nop       
/* 4F801C 8021843C 00000022 */  neg       $zero, $zero
/* 4F8020 80218440 00000000 */  nop       
/* 4F8024 80218444 00000024 */  and       $zero, $zero, $zero
/* 4F8028 80218448 00000000 */  nop       
/* 4F802C 8021844C 00000023 */  negu      $zero, $zero
/* 4F8030 80218450 00000000 */  nop       
/* 4F8034 80218454 00000021 */  addu      $zero, $zero, $zero
/* 4F8038 80218458 00000000 */  nop       
/* 4F803C 8021845C 00000026 */  xor       $zero, $zero, $zero
/* 4F8040 80218460 00000000 */  nop       
/* 4F8044 80218464 00000027 */  not       $zero, $zero
/* 4F8048 80218468 00000000 */  nop       
/* 4F804C 8021846C 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4F8050 80218470 00000000 */  nop       
/* 4F8054 80218474 00000000 */  nop       
/* 4F8058 80218478 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 4F805C 8021847C 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 4F8060 80218480 001400FF */  dsra32    $zero, $s4, 3
/* 4F8064 80218484 802184C4 */  lb        $at, -0x7b3c($at)
/* 4F8068 80218488 802183C0 */  lb        $at, -0x7c40($at)
/* 4F806C 8021848C 00000000 */  nop       
/* 4F8070 80218490 00000000 */  nop       
/* 4F8074 80218494 00F60000 */  .byte     0x00, 0xf6, 0x00, 0x00
/* 4F8078 80218498 00000000 */  nop       
/* 4F807C 8021849C 00000000 */  nop       
/* 4F8080 802184A0 001A0B06 */  .byte     0x00, 0x1a, 0x0b, 0x06
/* 4F8084 802184A4 00010000 */  sll       $zero, $at, 0
/* 4F8088 802184A8 80218478 */  lb        $at, -0x7b88($at)
/* 4F808C 802184AC 80218510 */  lb        $at, -0x7af0($at)
/* 4F8090 802184B0 802183CC */  lb        $at, -0x7c34($at)
/* 4F8094 802184B4 285A5A55 */  slti      $k0, $v0, 0x5a55
/* 4F8098 802184B8 5F006401 */  bgtzl     $t8, .L802314C0
/* 4F809C 802184BC 211C0000 */   addi     $gp, $t0, 0
/* 4F80A0 802184C0 F6140A14 */  sdc1      $f20, 0xa14($s0)
/* 4F80A4 802184C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F80A8 802184C8 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F80AC 802184CC 0000000C */  syscall   
/* 4F80B0 802184D0 002B0100 */  .byte     0x00, 0x2b, 0x01, 0x00
/* 4F80B4 802184D4 00000006 */  srlv      $zero, $zero, $zero
/* 4F80B8 802184D8 002B010E */  .byte     0x00, 0x2b, 0x01, 0x0e
/* 4F80BC 802184DC 00000009 */  jr        $zero
/* 4F80C0 802184E0 002B0101 */   .byte    0x00, 0x2b, 0x01, 0x01
/* 4F80C4 802184E4 00000008 */  jr        $zero
/* 4F80C8 802184E8 002B0100 */   .byte    0x00, 0x2b, 0x01, 0x00
/* 4F80CC 802184EC 0000000B */  movn      $zero, $zero, $zero
/* 4F80D0 802184F0 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F80D4 802184F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F80D8 802184F8 002B0100 */  .byte     0x00, 0x2b, 0x01, 0x00
/* 4F80DC 802184FC 00000004 */  sllv      $zero, $zero, $zero
/* 4F80E0 80218500 002B010F */  sync      4
/* 4F80E4 80218504 00000003 */  sra       $zero, $zero, 0
/* 4F80E8 80218508 002B010F */  sync      4
/* 4F80EC 8021850C 00000000 */  nop       
/* 4F80F0 80218510 00000043 */  sra       $zero, $zero, 1
/* 4F80F4 80218514 00000003 */  sra       $zero, $zero, 0
/* 4F80F8 80218518 80278930 */  lb        $a3, -0x76d0($at)
/* 4F80FC 8021851C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8100 80218520 8021A61C */  lb        $at, -0x59e4($at)
/* 4F8104 80218524 00000043 */  sra       $zero, $zero, 1
/* 4F8108 80218528 00000003 */  sra       $zero, $zero, 0
/* 4F810C 8021852C 80278A94 */  lb        $a3, -0x756c($at)
/* 4F8110 80218530 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8114 80218534 80218574 */  lb        $at, -0x7a8c($at)
/* 4F8118 80218538 00000043 */  sra       $zero, $zero, 1
/* 4F811C 8021853C 00000003 */  sra       $zero, $zero, 0
/* 4F8120 80218540 80278C20 */  lb        $a3, -0x73e0($at)
/* 4F8124 80218544 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8128 80218548 80218584 */  lb        $at, -0x7a7c($at)
/* 4F812C 8021854C 00000043 */  sra       $zero, $zero, 1
/* 4F8130 80218550 00000004 */  sllv      $zero, $zero, $zero
/* 4F8134 80218554 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F8138 80218558 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F813C 8021855C 00000000 */  nop       
/* 4F8140 80218560 00000000 */  nop       
/* 4F8144 80218564 00000002 */  srl       $zero, $zero, 0
/* 4F8148 80218568 00000000 */  nop       
/* 4F814C 8021856C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8150 80218570 00000000 */  nop       
/* 4F8154 80218574 00000002 */  srl       $zero, $zero, 0
/* 4F8158 80218578 00000000 */  nop       
/* 4F815C 8021857C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8160 80218580 00000000 */  nop       
/* 4F8164 80218584 00000043 */  sra       $zero, $zero, 1
/* 4F8168 80218588 00000003 */  sra       $zero, $zero, 0
/* 4F816C 8021858C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F8170 80218590 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8174 80218594 00000000 */  nop       
/* 4F8178 80218598 00000043 */  sra       $zero, $zero, 1
/* 4F817C 8021859C 00000003 */  sra       $zero, $zero, 0
/* 4F8180 802185A0 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F8184 802185A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8188 802185A8 00000000 */  nop       
/* 4F818C 802185AC 00000043 */  sra       $zero, $zero, 1
/* 4F8190 802185B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8194 802185B4 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F8198 802185B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F819C 802185BC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F81A0 802185C0 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F81A4 802185C4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F81A8 802185C8 00000043 */  sra       $zero, $zero, 1
/* 4F81AC 802185CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F81B0 802185D0 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F81B4 802185D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F81B8 802185D8 00000000 */  nop       
/* 4F81BC 802185DC 00000000 */  nop       
/* 4F81C0 802185E0 00000000 */  nop       
/* 4F81C4 802185E4 00000043 */  sra       $zero, $zero, 1
/* 4F81C8 802185E8 00000003 */  sra       $zero, $zero, 0
/* 4F81CC 802185EC 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 4F81D0 802185F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F81D4 802185F4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F81D8 802185F8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F81DC 802185FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F81E0 80218600 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F81E4 80218604 0000001D */  dmultu    $zero, $zero
/* 4F81E8 80218608 00000001 */  movf      $zero, $zero, $fcc0
/* 4F81EC 8021860C 00000009 */  jr        $zero
/* 4F81F0 80218610 0000001D */   dmultu   $zero, $zero
/* 4F81F4 80218614 00000001 */  movf      $zero, $zero, $fcc0
/* 4F81F8 80218618 0000000A */  movz      $zero, $zero, $zero
/* 4F81FC 8021861C 00000043 */  sra       $zero, $zero, 1
/* 4F8200 80218620 00000002 */  srl       $zero, $zero, 0
/* 4F8204 80218624 80269E54 */  lb        $a2, -0x61ac($at)
/* 4F8208 80218628 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F820C 8021862C 00000010 */  mfhi      $zero
/* 4F8210 80218630 00000002 */  srl       $zero, $zero, 0
/* 4F8214 80218634 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8218 80218638 00000020 */  add       $zero, $zero, $zero
/* 4F821C 8021863C 00000025 */  or        $zero, $zero, $zero
/* 4F8220 80218640 00000002 */  srl       $zero, $zero, 0
/* 4F8224 80218644 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8228 80218648 00000001 */  movf      $zero, $zero, $fcc0
/* 4F822C 8021864C 00000025 */  or        $zero, $zero, $zero
/* 4F8230 80218650 00000002 */  srl       $zero, $zero, 0
/* 4F8234 80218654 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8238 80218658 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F823C 8021865C 00000012 */  mflo      $zero
/* 4F8240 80218660 00000000 */  nop       
/* 4F8244 80218664 00000025 */  or        $zero, $zero, $zero
/* 4F8248 80218668 00000002 */  srl       $zero, $zero, 0
/* 4F824C 8021866C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8250 80218670 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8254 80218674 00000025 */  or        $zero, $zero, $zero
/* 4F8258 80218678 00000002 */  srl       $zero, $zero, 0
/* 4F825C 8021867C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8260 80218680 002B0108 */  .byte     0x00, 0x2b, 0x01, 0x08
/* 4F8264 80218684 00000013 */  mtlo      $zero
/* 4F8268 80218688 00000000 */  nop       
/* 4F826C 8021868C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8270 80218690 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8274 80218694 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F8278 80218698 00000020 */  add       $zero, $zero, $zero
/* 4F827C 8021869C 00000000 */  nop       
/* 4F8280 802186A0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8284 802186A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8288 802186A8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4F828C 802186AC 00000025 */  or        $zero, $zero, $zero
/* 4F8290 802186B0 00000002 */  srl       $zero, $zero, 0
/* 4F8294 802186B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8298 802186B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F829C 802186BC 00000025 */  or        $zero, $zero, $zero
/* 4F82A0 802186C0 00000002 */  srl       $zero, $zero, 0
/* 4F82A4 802186C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F82A8 802186C8 002B0110 */  .byte     0x00, 0x2b, 0x01, 0x10
/* 4F82AC 802186CC 00000025 */  or        $zero, $zero, $zero
/* 4F82B0 802186D0 00000002 */  srl       $zero, $zero, 0
/* 4F82B4 802186D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F82B8 802186D8 002B0112 */  .byte     0x00, 0x2b, 0x01, 0x12
/* 4F82BC 802186DC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F82C0 802186E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F82C4 802186E4 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4F82C8 802186E8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F82CC 802186EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F82D0 802186F0 00000024 */  and       $zero, $zero, $zero
/* 4F82D4 802186F4 00000025 */  or        $zero, $zero, $zero
/* 4F82D8 802186F8 00000002 */  srl       $zero, $zero, 0
/* 4F82DC 802186FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F82E0 80218700 00000001 */  movf      $zero, $zero, $fcc0
/* 4F82E4 80218704 00000025 */  or        $zero, $zero, $zero
/* 4F82E8 80218708 00000002 */  srl       $zero, $zero, 0
/* 4F82EC 8021870C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F82F0 80218710 002B0110 */  .byte     0x00, 0x2b, 0x01, 0x10
/* 4F82F4 80218714 00000025 */  or        $zero, $zero, $zero
/* 4F82F8 80218718 00000002 */  srl       $zero, $zero, 0
/* 4F82FC 8021871C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8300 80218720 002B0112 */  .byte     0x00, 0x2b, 0x01, 0x12
/* 4F8304 80218724 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8308 80218728 00000001 */  movf      $zero, $zero, $fcc0
/* 4F830C 8021872C 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4F8310 80218730 00000025 */  or        $zero, $zero, $zero
/* 4F8314 80218734 00000002 */  srl       $zero, $zero, 0
/* 4F8318 80218738 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F831C 8021873C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8320 80218740 00000025 */  or        $zero, $zero, $zero
/* 4F8324 80218744 00000002 */  srl       $zero, $zero, 0
/* 4F8328 80218748 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F832C 8021874C 002B0112 */  .byte     0x00, 0x2b, 0x01, 0x12
/* 4F8330 80218750 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8334 80218754 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8338 80218758 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F833C 8021875C 00000002 */  srl       $zero, $zero, 0
/* 4F8340 80218760 00000000 */  nop       
/* 4F8344 80218764 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8348 80218768 00000001 */  movf      $zero, $zero, $fcc0
/* 4F834C 8021876C 0000000B */  movn      $zero, $zero, $zero
/* 4F8350 80218770 00000025 */  or        $zero, $zero, $zero
/* 4F8354 80218774 00000002 */  srl       $zero, $zero, 0
/* 4F8358 80218778 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F835C 8021877C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8360 80218780 00000025 */  or        $zero, $zero, $zero
/* 4F8364 80218784 00000002 */  srl       $zero, $zero, 0
/* 4F8368 80218788 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F836C 8021878C 002B0108 */  .byte     0x00, 0x2b, 0x01, 0x08
/* 4F8370 80218790 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8374 80218794 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8378 80218798 8029B998 */  lb        $t1, -0x4668($at)
/* 4F837C 8021879C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8380 802187A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8384 802187A4 00000021 */  addu      $zero, $zero, $zero
/* 4F8388 802187A8 00000025 */  or        $zero, $zero, $zero
/* 4F838C 802187AC 00000002 */  srl       $zero, $zero, 0
/* 4F8390 802187B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8394 802187B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8398 802187B8 00000025 */  or        $zero, $zero, $zero
/* 4F839C 802187BC 00000002 */  srl       $zero, $zero, 0
/* 4F83A0 802187C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F83A4 802187C4 002B0108 */  .byte     0x00, 0x2b, 0x01, 0x08
/* 4F83A8 802187C8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F83AC 802187CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F83B0 802187D0 8029B998 */  lb        $t1, -0x4668($at)
/* 4F83B4 802187D4 00000025 */  or        $zero, $zero, $zero
/* 4F83B8 802187D8 00000002 */  srl       $zero, $zero, 0
/* 4F83BC 802187DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F83C0 802187E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F83C4 802187E4 00000025 */  or        $zero, $zero, $zero
/* 4F83C8 802187E8 00000002 */  srl       $zero, $zero, 0
/* 4F83CC 802187EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F83D0 802187F0 002B0108 */  .byte     0x00, 0x2b, 0x01, 0x08
/* 4F83D4 802187F4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F83D8 802187F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F83DC 802187FC 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F83E0 80218800 00000002 */  srl       $zero, $zero, 0
/* 4F83E4 80218804 00000000 */  nop       
/* 4F83E8 80218808 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F83EC 8021880C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F83F0 80218810 0000002F */  dsubu     $zero, $zero, $zero
/* 4F83F4 80218814 00000043 */  sra       $zero, $zero, 1
/* 4F83F8 80218818 00000001 */  movf      $zero, $zero, $fcc0
/* 4F83FC 8021881C 80269470 */  lb        $a2, -0x6b90($at)
/* 4F8400 80218820 00000025 */  or        $zero, $zero, $zero
/* 4F8404 80218824 00000002 */  srl       $zero, $zero, 0
/* 4F8408 80218828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F840C 8021882C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8410 80218830 00000025 */  or        $zero, $zero, $zero
/* 4F8414 80218834 00000002 */  srl       $zero, $zero, 0
/* 4F8418 80218838 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F841C 8021883C 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F8420 80218840 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8424 80218844 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8428 80218848 8029A6FC */  lb        $t1, -0x5904($at)
/* 4F842C 8021884C 00000025 */  or        $zero, $zero, $zero
/* 4F8430 80218850 00000002 */  srl       $zero, $zero, 0
/* 4F8434 80218854 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8438 80218858 00000001 */  movf      $zero, $zero, $fcc0
/* 4F843C 8021885C 00000025 */  or        $zero, $zero, $zero
/* 4F8440 80218860 00000002 */  srl       $zero, $zero, 0
/* 4F8444 80218864 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8448 80218868 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F844C 8021886C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8450 80218870 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8454 80218874 8029BD70 */  lb        $t1, -0x4290($at)
/* 4F8458 80218878 00000043 */  sra       $zero, $zero, 1
/* 4F845C 8021887C 00000006 */  srlv      $zero, $zero, $zero
/* 4F8460 80218880 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F8464 80218884 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8468 80218888 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F846C 8021888C 00000000 */  nop       
/* 4F8470 80218890 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8474 80218894 00000000 */  nop       
/* 4F8478 80218898 00000025 */  or        $zero, $zero, $zero
/* 4F847C 8021889C 00000002 */  srl       $zero, $zero, 0
/* 4F8480 802188A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8484 802188A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8488 802188A8 00000025 */  or        $zero, $zero, $zero
/* 4F848C 802188AC 00000002 */  srl       $zero, $zero, 0
/* 4F8490 802188B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8494 802188B4 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F8498 802188B8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F849C 802188BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F84A0 802188C0 8029C0A4 */  lb        $t1, -0x3f5c($at)
/* 4F84A4 802188C4 00000043 */  sra       $zero, $zero, 1
/* 4F84A8 802188C8 00000003 */  sra       $zero, $zero, 0
/* 4F84AC 802188CC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F84B0 802188D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F84B4 802188D4 F24A80E7 */  scd       $t2, -0x7f19($s2)
/* 4F84B8 802188D8 00000043 */  sra       $zero, $zero, 1
/* 4F84BC 802188DC 00000006 */  srlv      $zero, $zero, $zero
/* 4F84C0 802188E0 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F84C4 802188E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F84C8 802188E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F84CC 802188EC 00000000 */  nop       
/* 4F84D0 802188F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F84D4 802188F4 00000000 */  nop       
/* 4F84D8 802188F8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F84DC 802188FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F84E0 80218900 00000026 */  xor       $zero, $zero, $zero
/* 4F84E4 80218904 00000043 */  sra       $zero, $zero, 1
/* 4F84E8 80218908 00000001 */  movf      $zero, $zero, $fcc0
/* 4F84EC 8021890C 80269470 */  lb        $a2, -0x6b90($at)
/* 4F84F0 80218910 00000025 */  or        $zero, $zero, $zero
/* 4F84F4 80218914 00000002 */  srl       $zero, $zero, 0
/* 4F84F8 80218918 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F84FC 8021891C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8500 80218920 00000025 */  or        $zero, $zero, $zero
/* 4F8504 80218924 00000002 */  srl       $zero, $zero, 0
/* 4F8508 80218928 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F850C 8021892C 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F8510 80218930 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8514 80218934 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8518 80218938 8029A6FC */  lb        $t1, -0x5904($at)
/* 4F851C 8021893C 00000025 */  or        $zero, $zero, $zero
/* 4F8520 80218940 00000002 */  srl       $zero, $zero, 0
/* 4F8524 80218944 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8528 80218948 00000001 */  movf      $zero, $zero, $fcc0
/* 4F852C 8021894C 00000025 */  or        $zero, $zero, $zero
/* 4F8530 80218950 00000002 */  srl       $zero, $zero, 0
/* 4F8534 80218954 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8538 80218958 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F853C 8021895C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8540 80218960 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8544 80218964 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F8548 80218968 00000002 */  srl       $zero, $zero, 0
/* 4F854C 8021896C 00000000 */  nop       
/* 4F8550 80218970 0000001D */  dmultu    $zero, $zero
/* 4F8554 80218974 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8558 80218978 00000017 */  dsrav     $zero, $zero, $zero
/* 4F855C 8021897C 0000001D */  dmultu    $zero, $zero
/* 4F8560 80218980 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8564 80218984 00000019 */  multu     $zero, $zero
/* 4F8568 80218988 00000025 */  or        $zero, $zero, $zero
/* 4F856C 8021898C 00000002 */  srl       $zero, $zero, 0
/* 4F8570 80218990 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8574 80218994 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8578 80218998 00000025 */  or        $zero, $zero, $zero
/* 4F857C 8021899C 00000002 */  srl       $zero, $zero, 0
/* 4F8580 802189A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8584 802189A4 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F8588 802189A8 00000046 */  rotrv     $zero, $zero, $zero
/* 4F858C 802189AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8590 802189B0 8029AC70 */  lb        $t1, -0x5390($at)
/* 4F8594 802189B4 00000020 */  add       $zero, $zero, $zero
/* 4F8598 802189B8 00000000 */  nop       
/* 4F859C 802189BC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F85A0 802189C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F85A4 802189C4 00000020 */  add       $zero, $zero, $zero
/* 4F85A8 802189C8 00000043 */  sra       $zero, $zero, 1
/* 4F85AC 802189CC 00000002 */  srl       $zero, $zero, 0
/* 4F85B0 802189D0 80269E54 */  lb        $a2, -0x61ac($at)
/* 4F85B4 802189D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F85B8 802189D8 00000010 */  mfhi      $zero
/* 4F85BC 802189DC 00000002 */  srl       $zero, $zero, 0
/* 4F85C0 802189E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F85C4 802189E4 00000020 */  add       $zero, $zero, $zero
/* 4F85C8 802189E8 00000025 */  or        $zero, $zero, $zero
/* 4F85CC 802189EC 00000002 */  srl       $zero, $zero, 0
/* 4F85D0 802189F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F85D4 802189F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F85D8 802189F8 00000025 */  or        $zero, $zero, $zero
/* 4F85DC 802189FC 00000002 */  srl       $zero, $zero, 0
/* 4F85E0 80218A00 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F85E4 80218A04 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F85E8 80218A08 00000046 */  rotrv     $zero, $zero, $zero
/* 4F85EC 80218A0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F85F0 80218A10 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F85F4 80218A14 00000008 */  jr        $zero
/* 4F85F8 80218A18 00000001 */   movf     $zero, $zero, $fcc0
/* 4F85FC 80218A1C 0000000A */  movz      $zero, $zero, $zero
/* 4F8600 80218A20 00000025 */  or        $zero, $zero, $zero
/* 4F8604 80218A24 00000002 */  srl       $zero, $zero, 0
/* 4F8608 80218A28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F860C 80218A2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8610 80218A30 00000025 */  or        $zero, $zero, $zero
/* 4F8614 80218A34 00000002 */  srl       $zero, $zero, 0
/* 4F8618 80218A38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F861C 80218A3C 002B0113 */  .byte     0x00, 0x2b, 0x01, 0x13
/* 4F8620 80218A40 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8624 80218A44 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8628 80218A48 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F862C 80218A4C 00000012 */  mflo      $zero
/* 4F8630 80218A50 00000000 */  nop       
/* 4F8634 80218A54 00000025 */  or        $zero, $zero, $zero
/* 4F8638 80218A58 00000002 */  srl       $zero, $zero, 0
/* 4F863C 80218A5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8640 80218A60 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8644 80218A64 00000025 */  or        $zero, $zero, $zero
/* 4F8648 80218A68 00000002 */  srl       $zero, $zero, 0
/* 4F864C 80218A6C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8650 80218A70 002B0108 */  .byte     0x00, 0x2b, 0x01, 0x08
/* 4F8654 80218A74 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8658 80218A78 00000001 */  movf      $zero, $zero, $fcc0
/* 4F865C 80218A7C 80299044 */  lb        $t1, -0x6fbc($at)
/* 4F8660 80218A80 00000008 */  jr        $zero
/* 4F8664 80218A84 00000001 */   movf     $zero, $zero, $fcc0
/* 4F8668 80218A88 0000000A */  movz      $zero, $zero, $zero
/* 4F866C 80218A8C 00000025 */  or        $zero, $zero, $zero
/* 4F8670 80218A90 00000002 */  srl       $zero, $zero, 0
/* 4F8674 80218A94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8678 80218A98 00000001 */  movf      $zero, $zero, $fcc0
/* 4F867C 80218A9C 00000025 */  or        $zero, $zero, $zero
/* 4F8680 80218AA0 00000002 */  srl       $zero, $zero, 0
/* 4F8684 80218AA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8688 80218AA8 002B0108 */  .byte     0x00, 0x2b, 0x01, 0x08
/* 4F868C 80218AAC 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8690 80218AB0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8694 80218AB4 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4F8698 80218AB8 00000013 */  mtlo      $zero
/* 4F869C 80218ABC 00000000 */  nop       
/* 4F86A0 80218AC0 00000002 */  srl       $zero, $zero, 0
/* 4F86A4 80218AC4 00000000 */  nop       
/* 4F86A8 80218AC8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F86AC 80218ACC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F86B0 80218AD0 00000031 */  tgeu      $zero, $zero
/* 4F86B4 80218AD4 00000025 */  or        $zero, $zero, $zero
/* 4F86B8 80218AD8 00000002 */  srl       $zero, $zero, 0
/* 4F86BC 80218ADC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F86C0 80218AE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F86C4 80218AE4 00000025 */  or        $zero, $zero, $zero
/* 4F86C8 80218AE8 00000002 */  srl       $zero, $zero, 0
/* 4F86CC 80218AEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F86D0 80218AF0 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F86D4 80218AF4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F86D8 80218AF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F86DC 80218AFC 8029BFA0 */  lb        $t1, -0x4060($at)
/* 4F86E0 80218B00 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F86E4 80218B04 00000001 */  movf      $zero, $zero, $fcc0
/* 4F86E8 80218B08 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 4F86EC 80218B0C 00000025 */  or        $zero, $zero, $zero
/* 4F86F0 80218B10 00000002 */  srl       $zero, $zero, 0
/* 4F86F4 80218B14 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F86F8 80218B18 00000001 */  movf      $zero, $zero, $fcc0
/* 4F86FC 80218B1C 00000025 */  or        $zero, $zero, $zero
/* 4F8700 80218B20 00000002 */  srl       $zero, $zero, 0
/* 4F8704 80218B24 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8708 80218B28 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F870C 80218B2C 00000025 */  or        $zero, $zero, $zero
/* 4F8710 80218B30 00000002 */  srl       $zero, $zero, 0
/* 4F8714 80218B34 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8718 80218B38 002B0109 */  .byte     0x00, 0x2b, 0x01, 0x09
/* 4F871C 80218B3C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8720 80218B40 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8724 80218B44 8029B22C */  lb        $t1, -0x4dd4($at)
/* 4F8728 80218B48 00000002 */  srl       $zero, $zero, 0
/* 4F872C 80218B4C 00000000 */  nop       
/* 4F8730 80218B50 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8734 80218B54 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8738 80218B58 0000003A */  dsrl      $zero, $zero, 0
/* 4F873C 80218B5C 00000025 */  or        $zero, $zero, $zero
/* 4F8740 80218B60 00000002 */  srl       $zero, $zero, 0
/* 4F8744 80218B64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8748 80218B68 00000001 */  movf      $zero, $zero, $fcc0
/* 4F874C 80218B6C 00000025 */  or        $zero, $zero, $zero
/* 4F8750 80218B70 00000002 */  srl       $zero, $zero, 0
/* 4F8754 80218B74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8758 80218B78 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F875C 80218B7C 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8760 80218B80 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8764 80218B84 8029C37C */  lb        $t1, -0x3c84($at)
/* 4F8768 80218B88 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F876C 80218B8C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8770 80218B90 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8774 80218B94 00000025 */  or        $zero, $zero, $zero
/* 4F8778 80218B98 00000002 */  srl       $zero, $zero, 0
/* 4F877C 80218B9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8780 80218BA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8784 80218BA4 00000025 */  or        $zero, $zero, $zero
/* 4F8788 80218BA8 00000002 */  srl       $zero, $zero, 0
/* 4F878C 80218BAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8790 80218BB0 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F8794 80218BB4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8798 80218BB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F879C 80218BBC 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 4F87A0 80218BC0 00000002 */  srl       $zero, $zero, 0
/* 4F87A4 80218BC4 00000000 */  nop       
/* 4F87A8 80218BC8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F87AC 80218BCC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F87B0 80218BD0 0000001F */  ddivu     $zero, $zero, $zero
/* 4F87B4 80218BD4 00000025 */  or        $zero, $zero, $zero
/* 4F87B8 80218BD8 00000002 */  srl       $zero, $zero, 0
/* 4F87BC 80218BDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F87C0 80218BE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F87C4 80218BE4 00000025 */  or        $zero, $zero, $zero
/* 4F87C8 80218BE8 00000002 */  srl       $zero, $zero, 0
/* 4F87CC 80218BEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F87D0 80218BF0 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F87D4 80218BF4 00000046 */  rotrv     $zero, $zero, $zero
/* 4F87D8 80218BF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F87DC 80218BFC 8029AC70 */  lb        $t1, -0x5390($at)
/* 4F87E0 80218C00 0000001C */  dmult     $zero, $zero
/* 4F87E4 80218C04 00000000 */  nop       
/* 4F87E8 80218C08 00000023 */  negu      $zero, $zero
/* 4F87EC 80218C0C 00000000 */  nop       
/* 4F87F0 80218C10 00000043 */  sra       $zero, $zero, 1
/* 4F87F4 80218C14 00000003 */  sra       $zero, $zero, 0
/* 4F87F8 80218C18 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F87FC 80218C1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8800 80218C20 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8804 80218C24 00000043 */  sra       $zero, $zero, 1
/* 4F8808 80218C28 00000003 */  sra       $zero, $zero, 0
/* 4F880C 80218C2C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F8810 80218C30 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8814 80218C34 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8818 80218C38 00000002 */  srl       $zero, $zero, 0
/* 4F881C 80218C3C 00000000 */  nop       
/* 4F8820 80218C40 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8824 80218C44 00000000 */  nop       
/* 4F8828 80218C48 00000043 */  sra       $zero, $zero, 1
/* 4F882C 80218C4C 00000003 */  sra       $zero, $zero, 0
/* 4F8830 80218C50 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F8834 80218C54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8838 80218C58 00000000 */  nop       
/* 4F883C 80218C5C 00000043 */  sra       $zero, $zero, 1
/* 4F8840 80218C60 00000003 */  sra       $zero, $zero, 0
/* 4F8844 80218C64 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F8848 80218C68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F884C 80218C6C 00000000 */  nop       
/* 4F8850 80218C70 00000043 */  sra       $zero, $zero, 1
/* 4F8854 80218C74 00000002 */  srl       $zero, $zero, 0
/* 4F8858 80218C78 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F885C 80218C7C 00000013 */  mtlo      $zero
/* 4F8860 80218C80 00000043 */  sra       $zero, $zero, 1
/* 4F8864 80218C84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8868 80218C88 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F886C 80218C8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8870 80218C90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8874 80218C94 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8878 80218C98 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F887C 80218C9C 00000043 */  sra       $zero, $zero, 1
/* 4F8880 80218CA0 00000004 */  sllv      $zero, $zero, $zero
/* 4F8884 80218CA4 8024E90C */  lb        $a0, -0x16f4($at)
/* 4F8888 80218CA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F888C 80218CAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8890 80218CB0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8894 80218CB4 00000043 */  sra       $zero, $zero, 1
/* 4F8898 80218CB8 00000002 */  srl       $zero, $zero, 0
/* 4F889C 80218CBC 8024EC6C */  lb        $a0, -0x1394($at)
/* 4F88A0 80218CC0 0000014A */  .byte     0x00, 0x00, 0x01, 0x4a
/* 4F88A4 80218CC4 00000043 */  sra       $zero, $zero, 1
/* 4F88A8 80218CC8 00000002 */  srl       $zero, $zero, 0
/* 4F88AC 80218CCC 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4F88B0 80218CD0 0000001E */  ddiv      $zero, $zero, $zero
/* 4F88B4 80218CD4 00000043 */  sra       $zero, $zero, 1
/* 4F88B8 80218CD8 00000002 */  srl       $zero, $zero, 0
/* 4F88BC 80218CDC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F88C0 80218CE0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F88C4 80218CE4 00000008 */  jr        $zero
/* 4F88C8 80218CE8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F88CC 80218CEC 00000014 */  dsllv     $zero, $zero, $zero
/* 4F88D0 80218CF0 00000043 */  sra       $zero, $zero, 1
/* 4F88D4 80218CF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F88D8 80218CF8 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F88DC 80218CFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F88E0 80218D00 00000000 */  nop       
/* 4F88E4 80218D04 00000000 */  nop       
/* 4F88E8 80218D08 00000000 */  nop       
/* 4F88EC 80218D0C 00000043 */  sra       $zero, $zero, 1
/* 4F88F0 80218D10 00000002 */  srl       $zero, $zero, 0
/* 4F88F4 80218D14 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F88F8 80218D18 00000001 */  movf      $zero, $zero, $fcc0
/* 4F88FC 80218D1C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F8900 80218D20 00000000 */  nop       
/* 4F8904 80218D24 00000008 */  jr        $zero
/* 4F8908 80218D28 00000001 */   movf     $zero, $zero, $fcc0
/* 4F890C 80218D2C 0000001E */  ddiv      $zero, $zero, $zero
/* 4F8910 80218D30 00000043 */  sra       $zero, $zero, 1
/* 4F8914 80218D34 00000003 */  sra       $zero, $zero, 0
/* 4F8918 80218D38 8025385C */  lb        $a1, 0x385c($at)
/* 4F891C 80218D3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8920 80218D40 0000206E */  .byte     0x00, 0x00, 0x20, 0x6e
/* 4F8924 80218D44 00000008 */  jr        $zero
/* 4F8928 80218D48 00000001 */   movf     $zero, $zero, $fcc0
/* 4F892C 80218D4C 0000001E */  ddiv      $zero, $zero, $zero
/* 4F8930 80218D50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8934 80218D54 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8938 80218D58 00000004 */  sllv      $zero, $zero, $zero
/* 4F893C 80218D5C 00000043 */  sra       $zero, $zero, 1
/* 4F8940 80218D60 00000003 */  sra       $zero, $zero, 0
/* 4F8944 80218D64 8025385C */  lb        $a1, 0x385c($at)
/* 4F8948 80218D68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F894C 80218D6C 0000206F */  .byte     0x00, 0x00, 0x20, 0x6f
/* 4F8950 80218D70 00000008 */  jr        $zero
/* 4F8954 80218D74 00000001 */   movf     $zero, $zero, $fcc0
/* 4F8958 80218D78 0000000B */  movn      $zero, $zero, $zero
/* 4F895C 80218D7C 00000006 */  srlv      $zero, $zero, $zero
/* 4F8960 80218D80 00000000 */  nop       
/* 4F8964 80218D84 00000043 */  sra       $zero, $zero, 1
/* 4F8968 80218D88 00000003 */  sra       $zero, $zero, 0
/* 4F896C 80218D8C 8025385C */  lb        $a1, 0x385c($at)
/* 4F8970 80218D90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8974 80218D94 00002070 */  tge       $zero, $zero, 0x81
/* 4F8978 80218D98 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F897C 80218D9C 00000000 */  nop       
/* 4F8980 80218DA0 00000043 */  sra       $zero, $zero, 1
/* 4F8984 80218DA4 00000004 */  sllv      $zero, $zero, $zero
/* 4F8988 80218DA8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F898C 80218DAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8990 80218DB0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8994 80218DB4 002B010D */  break     0x2b, 4
/* 4F8998 80218DB8 00000008 */   jr       $zero
/* 4F899C 80218DBC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F89A0 80218DC0 00000082 */  srl       $zero, $zero, 2
/* 4F89A4 80218DC4 00000043 */  sra       $zero, $zero, 1
/* 4F89A8 80218DC8 00000004 */  sllv      $zero, $zero, $zero
/* 4F89AC 80218DCC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F89B0 80218DD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F89B4 80218DD4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F89B8 80218DD8 002B0102 */  rotr      $zero, $t3, 4
/* 4F89BC 80218DDC 00000043 */  sra       $zero, $zero, 1
/* 4F89C0 80218DE0 00000003 */  sra       $zero, $zero, 0
/* 4F89C4 80218DE4 8026DB64 */  lb        $a2, -0x249c($at)
/* 4F89C8 80218DE8 8021A800 */  lb        $at, -0x5800($at)
/* 4F89CC 80218DEC 00000000 */  nop       
/* 4F89D0 80218DF0 00000043 */  sra       $zero, $zero, 1
/* 4F89D4 80218DF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F89D8 80218DF8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F89DC 80218DFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F89E0 80218E00 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F89E4 80218E04 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F89E8 80218E08 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F89EC 80218E0C 00000043 */  sra       $zero, $zero, 1
/* 4F89F0 80218E10 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F89F4 80218E14 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4F89F8 80218E18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F89FC 80218E1C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8A00 80218E20 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8A04 80218E24 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F8A08 80218E28 00000043 */  sra       $zero, $zero, 1
/* 4F8A0C 80218E2C 00000003 */  sra       $zero, $zero, 0
/* 4F8A10 80218E30 80269F94 */  lb        $a2, -0x606c($at)
/* 4F8A14 80218E34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8A18 80218E38 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F8A1C 80218E3C 00000043 */  sra       $zero, $zero, 1
/* 4F8A20 80218E40 00000002 */  srl       $zero, $zero, 0
/* 4F8A24 80218E44 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F8A28 80218E48 00000002 */  srl       $zero, $zero, 0
/* 4F8A2C 80218E4C 00000043 */  sra       $zero, $zero, 1
/* 4F8A30 80218E50 00000002 */  srl       $zero, $zero, 0
/* 4F8A34 80218E54 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4F8A38 80218E58 00000014 */  dsllv     $zero, $zero, $zero
/* 4F8A3C 80218E5C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F8A40 80218E60 00000000 */  nop       
/* 4F8A44 80218E64 00000043 */  sra       $zero, $zero, 1
/* 4F8A48 80218E68 00000004 */  sllv      $zero, $zero, $zero
/* 4F8A4C 80218E6C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8A50 80218E70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8A54 80218E74 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8A58 80218E78 002B0102 */  rotr      $zero, $t3, 4
/* 4F8A5C 80218E7C 00000043 */  sra       $zero, $zero, 1
/* 4F8A60 80218E80 00000003 */  sra       $zero, $zero, 0
/* 4F8A64 80218E84 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F8A68 80218E88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8A6C 80218E8C F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F8A70 80218E90 00000043 */  sra       $zero, $zero, 1
/* 4F8A74 80218E94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8A78 80218E98 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F8A7C 80218E9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8A80 80218EA0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8A84 80218EA4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8A88 80218EA8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F8A8C 80218EAC 00000043 */  sra       $zero, $zero, 1
/* 4F8A90 80218EB0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8A94 80218EB4 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F8A98 80218EB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8A9C 80218EBC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8AA0 80218EC0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8AA4 80218EC4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F8AA8 80218EC8 00000043 */  sra       $zero, $zero, 1
/* 4F8AAC 80218ECC 00000006 */  srlv      $zero, $zero, $zero
/* 4F8AB0 80218ED0 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F8AB4 80218ED4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8AB8 80218ED8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4F8ABC 80218EDC 00000000 */  nop       
/* 4F8AC0 80218EE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8AC4 80218EE4 00000000 */  nop       
/* 4F8AC8 80218EE8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F8ACC 80218EEC 00000000 */  nop       
/* 4F8AD0 80218EF0 00000008 */  jr        $zero
/* 4F8AD4 80218EF4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F8AD8 80218EF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8ADC 80218EFC 00000043 */  sra       $zero, $zero, 1
/* 4F8AE0 80218F00 00000004 */  sllv      $zero, $zero, $zero
/* 4F8AE4 80218F04 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8AE8 80218F08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8AEC 80218F0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8AF0 80218F10 002B0102 */  rotr      $zero, $t3, 4
/* 4F8AF4 80218F14 00000043 */  sra       $zero, $zero, 1
/* 4F8AF8 80218F18 00000003 */  sra       $zero, $zero, 0
/* 4F8AFC 80218F1C 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F8B00 80218F20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8B04 80218F24 F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F8B08 80218F28 00000043 */  sra       $zero, $zero, 1
/* 4F8B0C 80218F2C 00000006 */  srlv      $zero, $zero, $zero
/* 4F8B10 80218F30 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F8B14 80218F34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8B18 80218F38 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4F8B1C 80218F3C 00000000 */  nop       
/* 4F8B20 80218F40 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8B24 80218F44 00000000 */  nop       
/* 4F8B28 80218F48 00000043 */  sra       $zero, $zero, 1
/* 4F8B2C 80218F4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8B30 80218F50 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F8B34 80218F54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8B38 80218F58 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8B3C 80218F5C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8B40 80218F60 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F8B44 80218F64 00000043 */  sra       $zero, $zero, 1
/* 4F8B48 80218F68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8B4C 80218F6C 8026A1EC */  lb        $a2, -0x5e14($at)
/* 4F8B50 80218F70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8B54 80218F74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8B58 80218F78 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8B5C 80218F7C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F8B60 80218F80 00000043 */  sra       $zero, $zero, 1
/* 4F8B64 80218F84 00000002 */  srl       $zero, $zero, 0
/* 4F8B68 80218F88 8026D664 */  lb        $a2, -0x299c($at)
/* 4F8B6C 80218F8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8B70 80218F90 00000043 */  sra       $zero, $zero, 1
/* 4F8B74 80218F94 00000004 */  sllv      $zero, $zero, $zero
/* 4F8B78 80218F98 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8B7C 80218F9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8B80 80218FA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8B84 80218FA4 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F8B88 80218FA8 00000043 */  sra       $zero, $zero, 1
/* 4F8B8C 80218FAC 00000004 */  sllv      $zero, $zero, $zero
/* 4F8B90 80218FB0 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4F8B94 80218FB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8B98 80218FB8 00000000 */  nop       
/* 4F8B9C 80218FBC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8BA0 80218FC0 00000014 */  dsllv     $zero, $zero, $zero
/* 4F8BA4 80218FC4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8BA8 80218FC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8BAC 80218FCC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8BB0 80218FD0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8BB4 80218FD4 00000000 */  nop       
/* 4F8BB8 80218FD8 00000043 */  sra       $zero, $zero, 1
/* 4F8BBC 80218FDC 00000004 */  sllv      $zero, $zero, $zero
/* 4F8BC0 80218FE0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F8BC4 80218FE4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8BC8 80218FE8 00000000 */  nop       
/* 4F8BCC 80218FEC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8BD0 80218FF0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F8BD4 80218FF4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8BD8 80218FF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8BDC 80218FFC 00000043 */  sra       $zero, $zero, 1
/* 4F8BE0 80219000 00000004 */  sllv      $zero, $zero, $zero
/* 4F8BE4 80219004 8026C044 */  lb        $a2, -0x3fbc($at)
/* 4F8BE8 80219008 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8BEC 8021900C 00000000 */  nop       
/* 4F8BF0 80219010 00000002 */  srl       $zero, $zero, 0
/* 4F8BF4 80219014 00000023 */  negu      $zero, $zero
/* 4F8BF8 80219018 00000000 */  nop       
/* 4F8BFC 8021901C 00000043 */  sra       $zero, $zero, 1
/* 4F8C00 80219020 00000003 */  sra       $zero, $zero, 0
/* 4F8C04 80219024 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F8C08 80219028 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8C0C 8021902C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8C10 80219030 00000043 */  sra       $zero, $zero, 1
/* 4F8C14 80219034 00000003 */  sra       $zero, $zero, 0
/* 4F8C18 80219038 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F8C1C 8021903C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8C20 80219040 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8C24 80219044 00000002 */  srl       $zero, $zero, 0
/* 4F8C28 80219048 00000000 */  nop       
/* 4F8C2C 8021904C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8C30 80219050 00000000 */  nop       
/* 4F8C34 80219054 00000043 */  sra       $zero, $zero, 1
/* 4F8C38 80219058 00000003 */  sra       $zero, $zero, 0
/* 4F8C3C 8021905C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F8C40 80219060 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8C44 80219064 00000000 */  nop       
/* 4F8C48 80219068 00000043 */  sra       $zero, $zero, 1
/* 4F8C4C 8021906C 00000003 */  sra       $zero, $zero, 0
/* 4F8C50 80219070 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F8C54 80219074 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8C58 80219078 00000000 */  nop       
/* 4F8C5C 8021907C 00000043 */  sra       $zero, $zero, 1
/* 4F8C60 80219080 00000002 */  srl       $zero, $zero, 0
/* 4F8C64 80219084 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F8C68 80219088 0000003F */  dsra32    $zero, $zero, 0
/* 4F8C6C 8021908C 00000043 */  sra       $zero, $zero, 1
/* 4F8C70 80219090 00000002 */  srl       $zero, $zero, 0
/* 4F8C74 80219094 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4F8C78 80219098 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8C7C 8021909C 00000043 */  sra       $zero, $zero, 1
/* 4F8C80 802190A0 00000004 */  sllv      $zero, $zero, $zero
/* 4F8C84 802190A4 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4F8C88 802190A8 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F8C8C 802190AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8C90 802190B0 00000000 */  nop       
/* 4F8C94 802190B4 00000043 */  sra       $zero, $zero, 1
/* 4F8C98 802190B8 00000002 */  srl       $zero, $zero, 0
/* 4F8C9C 802190BC 80269E28 */  lb        $a2, -0x61d8($at)
/* 4F8CA0 802190C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8CA4 802190C4 0000000A */  movz      $zero, $zero, $zero
/* 4F8CA8 802190C8 00000002 */  srl       $zero, $zero, 0
/* 4F8CAC 802190CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8CB0 802190D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8CB4 802190D4 00000043 */  sra       $zero, $zero, 1
/* 4F8CB8 802190D8 00000002 */  srl       $zero, $zero, 0
/* 4F8CBC 802190DC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F8CC0 802190E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8CC4 802190E4 00000043 */  sra       $zero, $zero, 1
/* 4F8CC8 802190E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8CCC 802190EC 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F8CD0 802190F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8CD4 802190F4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8CD8 802190F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8CDC 802190FC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8CE0 80219100 00000027 */  not       $zero, $zero
/* 4F8CE4 80219104 00000002 */  srl       $zero, $zero, 0
/* 4F8CE8 80219108 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8CEC 8021910C 00000032 */  tlt       $zero, $zero
/* 4F8CF0 80219110 00000024 */  and       $zero, $zero, $zero
/* 4F8CF4 80219114 00000002 */  srl       $zero, $zero, 0
/* 4F8CF8 80219118 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8CFC 8021911C 00000000 */  nop       
/* 4F8D00 80219120 00000043 */  sra       $zero, $zero, 1
/* 4F8D04 80219124 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8D08 80219128 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4F8D0C 8021912C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8D10 80219130 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8D14 80219134 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8D18 80219138 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8D1C 8021913C 00000004 */  sllv      $zero, $zero, $zero
/* 4F8D20 80219140 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8D24 80219144 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4F8D28 80219148 00000013 */  mtlo      $zero
/* 4F8D2C 8021914C 00000000 */  nop       
/* 4F8D30 80219150 00000043 */  sra       $zero, $zero, 1
/* 4F8D34 80219154 00000003 */  sra       $zero, $zero, 0
/* 4F8D38 80219158 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4F8D3C 8021915C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8D40 80219160 00000000 */  nop       
/* 4F8D44 80219164 00000043 */  sra       $zero, $zero, 1
/* 4F8D48 80219168 00000004 */  sllv      $zero, $zero, $zero
/* 4F8D4C 8021916C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8D50 80219170 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8D54 80219174 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8D58 80219178 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F8D5C 8021917C 00000043 */  sra       $zero, $zero, 1
/* 4F8D60 80219180 00000002 */  srl       $zero, $zero, 0
/* 4F8D64 80219184 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F8D68 80219188 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8D6C 8021918C 00000043 */  sra       $zero, $zero, 1
/* 4F8D70 80219190 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8D74 80219194 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F8D78 80219198 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8D7C 8021919C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8D80 802191A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8D84 802191A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8D88 802191A8 00000027 */  not       $zero, $zero
/* 4F8D8C 802191AC 00000002 */  srl       $zero, $zero, 0
/* 4F8D90 802191B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8D94 802191B4 00000032 */  tlt       $zero, $zero
/* 4F8D98 802191B8 00000024 */  and       $zero, $zero, $zero
/* 4F8D9C 802191BC 00000002 */  srl       $zero, $zero, 0
/* 4F8DA0 802191C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8DA4 802191C4 00000000 */  nop       
/* 4F8DA8 802191C8 00000043 */  sra       $zero, $zero, 1
/* 4F8DAC 802191CC 00000003 */  sra       $zero, $zero, 0
/* 4F8DB0 802191D0 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F8DB4 802191D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8DB8 802191D8 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4F8DBC 802191DC 00000043 */  sra       $zero, $zero, 1
/* 4F8DC0 802191E0 00000003 */  sra       $zero, $zero, 0
/* 4F8DC4 802191E4 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F8DC8 802191E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8DCC 802191EC F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F8DD0 802191F0 00000046 */  rotrv     $zero, $zero, $zero
/* 4F8DD4 802191F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8DD8 802191F8 8029C12C */  lb        $t1, -0x3ed4($at)
/* 4F8DDC 802191FC 00000043 */  sra       $zero, $zero, 1
/* 4F8DE0 80219200 00000004 */  sllv      $zero, $zero, $zero
/* 4F8DE4 80219204 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8DE8 80219208 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8DEC 8021920C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8DF0 80219210 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F8DF4 80219214 00000003 */  sra       $zero, $zero, 0
/* 4F8DF8 80219218 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8DFC 8021921C 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4F8E00 80219220 00000043 */  sra       $zero, $zero, 1
/* 4F8E04 80219224 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8E08 80219228 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F8E0C 8021922C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8E10 80219230 00000000 */  nop       
/* 4F8E14 80219234 0000000A */  movz      $zero, $zero, $zero
/* 4F8E18 80219238 00000000 */  nop       
/* 4F8E1C 8021923C 00000043 */  sra       $zero, $zero, 1
/* 4F8E20 80219240 00000004 */  sllv      $zero, $zero, $zero
/* 4F8E24 80219244 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8E28 80219248 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8E2C 8021924C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8E30 80219250 002B0104 */  .byte     0x00, 0x2b, 0x01, 0x04
/* 4F8E34 80219254 00000043 */  sra       $zero, $zero, 1
/* 4F8E38 80219258 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8E3C 8021925C 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F8E40 80219260 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8E44 80219264 00000000 */  nop       
/* 4F8E48 80219268 00000009 */  jr        $zero
/* 4F8E4C 8021926C 00000000 */   nop      
/* 4F8E50 80219270 00000008 */  jr        $zero
/* 4F8E54 80219274 00000001 */   movf     $zero, $zero, $fcc0
/* 4F8E58 80219278 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8E5C 8021927C 00000043 */  sra       $zero, $zero, 1
/* 4F8E60 80219280 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8E64 80219284 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F8E68 80219288 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8E6C 8021928C 00000000 */  nop       
/* 4F8E70 80219290 00000008 */  jr        $zero
/* 4F8E74 80219294 00000000 */   nop      
/* 4F8E78 80219298 00000008 */  jr        $zero
/* 4F8E7C 8021929C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F8E80 802192A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8E84 802192A4 00000043 */  sra       $zero, $zero, 1
/* 4F8E88 802192A8 00000007 */  srav      $zero, $zero, $zero
/* 4F8E8C 802192AC 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F8E90 802192B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8E94 802192B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8E98 802192B8 08000000 */  j         .L80000000
/* 4F8E9C 802192BC 00000000 */   nop      
/* 4F8EA0 802192C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8EA4 802192C4 00000010 */  mfhi      $zero
/* 4F8EA8 802192C8 00000014 */  dsllv     $zero, $zero, $zero
/* 4F8EAC 802192CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8EB0 802192D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8EB4 802192D4 0000001D */  dmultu    $zero, $zero
/* 4F8EB8 802192D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8EBC 802192DC 00000006 */  srlv      $zero, $zero, $zero
/* 4F8EC0 802192E0 0000001D */  dmultu    $zero, $zero
/* 4F8EC4 802192E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8EC8 802192E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8ECC 802192EC 00000024 */  and       $zero, $zero, $zero
/* 4F8ED0 802192F0 00000002 */  srl       $zero, $zero, 0
/* 4F8ED4 802192F4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F8ED8 802192F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8EDC 802192FC 00000043 */  sra       $zero, $zero, 1
/* 4F8EE0 80219300 00000002 */  srl       $zero, $zero, 0
/* 4F8EE4 80219304 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F8EE8 80219308 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8EEC 8021930C 00000043 */  sra       $zero, $zero, 1
/* 4F8EF0 80219310 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8EF4 80219314 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F8EF8 80219318 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8EFC 8021931C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8F00 80219320 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8F04 80219324 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8F08 80219328 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F8F0C 8021932C 00000002 */  srl       $zero, $zero, 0
/* 4F8F10 80219330 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8F14 80219334 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8F18 80219338 00000024 */  and       $zero, $zero, $zero
/* 4F8F1C 8021933C 00000002 */  srl       $zero, $zero, 0
/* 4F8F20 80219340 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8F24 80219344 00000000 */  nop       
/* 4F8F28 80219348 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F8F2C 8021934C 00000002 */  srl       $zero, $zero, 0
/* 4F8F30 80219350 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8F34 80219354 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8F38 80219358 00000043 */  sra       $zero, $zero, 1
/* 4F8F3C 8021935C 00000003 */  sra       $zero, $zero, 0
/* 4F8F40 80219360 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F8F44 80219364 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8F48 80219368 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4F8F4C 8021936C 00000043 */  sra       $zero, $zero, 1
/* 4F8F50 80219370 00000004 */  sllv      $zero, $zero, $zero
/* 4F8F54 80219374 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8F58 80219378 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8F5C 8021937C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8F60 80219380 002B0105 */  .byte     0x00, 0x2b, 0x01, 0x05
/* 4F8F64 80219384 00000043 */  sra       $zero, $zero, 1
/* 4F8F68 80219388 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8F6C 8021938C 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F8F70 80219390 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8F74 80219394 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8F78 80219398 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8F7C 8021939C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8F80 802193A0 00000043 */  sra       $zero, $zero, 1
/* 4F8F84 802193A4 00000006 */  srlv      $zero, $zero, $zero
/* 4F8F88 802193A8 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F8F8C 802193AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8F90 802193B0 0000000B */  movn      $zero, $zero, $zero
/* 4F8F94 802193B4 00000000 */  nop       
/* 4F8F98 802193B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8F9C 802193BC 00000000 */  nop       
/* 4F8FA0 802193C0 00000043 */  sra       $zero, $zero, 1
/* 4F8FA4 802193C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8FA8 802193C8 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F8FAC 802193CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8FB0 802193D0 00000000 */  nop       
/* 4F8FB4 802193D4 00000000 */  nop       
/* 4F8FB8 802193D8 00000000 */  nop       
/* 4F8FBC 802193DC 00000043 */  sra       $zero, $zero, 1
/* 4F8FC0 802193E0 00000004 */  sllv      $zero, $zero, $zero
/* 4F8FC4 802193E4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F8FC8 802193E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8FCC 802193EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F8FD0 802193F0 002B0109 */  .byte     0x00, 0x2b, 0x01, 0x09
/* 4F8FD4 802193F4 00000043 */  sra       $zero, $zero, 1
/* 4F8FD8 802193F8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F8FDC 802193FC 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F8FE0 80219400 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F8FE4 80219404 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8FE8 80219408 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F8FEC 8021940C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F8FF0 80219410 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F8FF4 80219414 00000002 */  srl       $zero, $zero, 0
/* 4F8FF8 80219418 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F8FFC 8021941C 00000014 */  dsllv     $zero, $zero, $zero
/* 4F9000 80219420 00000043 */  sra       $zero, $zero, 1
/* 4F9004 80219424 00000003 */  sra       $zero, $zero, 0
/* 4F9008 80219428 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F900C 8021942C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9010 80219430 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4F9014 80219434 00000043 */  sra       $zero, $zero, 1
/* 4F9018 80219438 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F901C 8021943C 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F9020 80219440 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9024 80219444 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9028 80219448 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F902C 8021944C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9030 80219450 00000043 */  sra       $zero, $zero, 1
/* 4F9034 80219454 00000006 */  srlv      $zero, $zero, $zero
/* 4F9038 80219458 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F903C 8021945C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9040 80219460 00000006 */  srlv      $zero, $zero, $zero
/* 4F9044 80219464 00000000 */  nop       
/* 4F9048 80219468 00000001 */  movf      $zero, $zero, $fcc0
/* 4F904C 8021946C 00000000 */  nop       
/* 4F9050 80219470 00000043 */  sra       $zero, $zero, 1
/* 4F9054 80219474 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9058 80219478 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F905C 8021947C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9060 80219480 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9064 80219484 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9068 80219488 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F906C 8021948C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F9070 80219490 00000002 */  srl       $zero, $zero, 0
/* 4F9074 80219494 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9078 80219498 0000000F */  sync      
/* 4F907C 8021949C 00000043 */  sra       $zero, $zero, 1
/* 4F9080 802194A0 00000003 */  sra       $zero, $zero, 0
/* 4F9084 802194A4 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F9088 802194A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F908C 802194AC F24A8680 */  scd       $t2, -0x7980($s2)
/* 4F9090 802194B0 00000043 */  sra       $zero, $zero, 1
/* 4F9094 802194B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9098 802194B8 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F909C 802194BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F90A0 802194C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F90A4 802194C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F90A8 802194C8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F90AC 802194CC 00000043 */  sra       $zero, $zero, 1
/* 4F90B0 802194D0 00000006 */  srlv      $zero, $zero, $zero
/* 4F90B4 802194D4 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F90B8 802194D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F90BC 802194DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F90C0 802194E0 00000000 */  nop       
/* 4F90C4 802194E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F90C8 802194E8 00000000 */  nop       
/* 4F90CC 802194EC 00000043 */  sra       $zero, $zero, 1
/* 4F90D0 802194F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F90D4 802194F4 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F90D8 802194F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F90DC 802194FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F90E0 80219500 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F90E4 80219504 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F90E8 80219508 00000008 */  jr        $zero
/* 4F90EC 8021950C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F90F0 80219510 00000004 */  sllv      $zero, $zero, $zero
/* 4F90F4 80219514 00000008 */  jr        $zero
/* 4F90F8 80219518 00000001 */   movf     $zero, $zero, $fcc0
/* 4F90FC 8021951C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9100 80219520 0000000A */  movz      $zero, $zero, $zero
/* 4F9104 80219524 00000002 */  srl       $zero, $zero, 0
/* 4F9108 80219528 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F910C 8021952C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9110 80219530 00000043 */  sra       $zero, $zero, 1
/* 4F9114 80219534 00000007 */  srav      $zero, $zero, $zero
/* 4F9118 80219538 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4F911C 8021953C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9120 80219540 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9124 80219544 80000000 */  lb        $zero, ($zero)
/* 4F9128 80219548 00000000 */  nop       
/* 4F912C 8021954C 00000000 */  nop       
/* 4F9130 80219550 00000000 */  nop       
/* 4F9134 80219554 00000013 */  mtlo      $zero
/* 4F9138 80219558 00000000 */  nop       
/* 4F913C 8021955C 00000008 */  jr        $zero
/* 4F9140 80219560 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9144 80219564 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9148 80219568 00000043 */  sra       $zero, $zero, 1
/* 4F914C 8021956C 00000002 */  srl       $zero, $zero, 0
/* 4F9150 80219570 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F9154 80219574 00000002 */  srl       $zero, $zero, 0
/* 4F9158 80219578 00000043 */  sra       $zero, $zero, 1
/* 4F915C 8021957C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9160 80219580 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4F9164 80219584 00000043 */  sra       $zero, $zero, 1
/* 4F9168 80219588 00000003 */  sra       $zero, $zero, 0
/* 4F916C 8021958C 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F9170 80219590 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9174 80219594 000000B4 */  teq       $zero, $zero, 2
/* 4F9178 80219598 00000043 */  sra       $zero, $zero, 1
/* 4F917C 8021959C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9180 802195A0 8026EE88 */  lb        $a2, -0x1178($at)
/* 4F9184 802195A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9188 802195A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F918C 802195AC 00000000 */  nop       
/* 4F9190 802195B0 00000002 */  srl       $zero, $zero, 0
/* 4F9194 802195B4 00000043 */  sra       $zero, $zero, 1
/* 4F9198 802195B8 00000004 */  sllv      $zero, $zero, $zero
/* 4F919C 802195BC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F91A0 802195C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F91A4 802195C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F91A8 802195C8 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F91AC 802195CC 00000043 */  sra       $zero, $zero, 1
/* 4F91B0 802195D0 00000002 */  srl       $zero, $zero, 0
/* 4F91B4 802195D4 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F91B8 802195D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F91BC 802195DC 00000043 */  sra       $zero, $zero, 1
/* 4F91C0 802195E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F91C4 802195E4 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F91C8 802195E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F91CC 802195EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F91D0 802195F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F91D4 802195F4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F91D8 802195F8 00000043 */  sra       $zero, $zero, 1
/* 4F91DC 802195FC 00000003 */  sra       $zero, $zero, 0
/* 4F91E0 80219600 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F91E4 80219604 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F91E8 80219608 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4F91EC 8021960C 00000043 */  sra       $zero, $zero, 1
/* 4F91F0 80219610 00000003 */  sra       $zero, $zero, 0
/* 4F91F4 80219614 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F91F8 80219618 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F91FC 8021961C F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F9200 80219620 00000046 */  rotrv     $zero, $zero, $zero
/* 4F9204 80219624 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9208 80219628 8029C12C */  lb        $t1, -0x3ed4($at)
/* 4F920C 8021962C 00000043 */  sra       $zero, $zero, 1
/* 4F9210 80219630 00000004 */  sllv      $zero, $zero, $zero
/* 4F9214 80219634 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4F9218 80219638 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F921C 8021963C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9220 80219640 00000000 */  nop       
/* 4F9224 80219644 00000043 */  sra       $zero, $zero, 1
/* 4F9228 80219648 00000003 */  sra       $zero, $zero, 0
/* 4F922C 8021964C 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4F9230 80219650 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9234 80219654 00000000 */  nop       
/* 4F9238 80219658 00000043 */  sra       $zero, $zero, 1
/* 4F923C 8021965C 00000003 */  sra       $zero, $zero, 0
/* 4F9240 80219660 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F9244 80219664 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9248 80219668 00000001 */  movf      $zero, $zero, $fcc0
/* 4F924C 8021966C 00000043 */  sra       $zero, $zero, 1
/* 4F9250 80219670 00000003 */  sra       $zero, $zero, 0
/* 4F9254 80219674 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F9258 80219678 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F925C 8021967C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9260 80219680 00000002 */  srl       $zero, $zero, 0
/* 4F9264 80219684 00000000 */  nop       
/* 4F9268 80219688 00000020 */  add       $zero, $zero, $zero
/* 4F926C 8021968C 00000000 */  nop       
/* 4F9270 80219690 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9274 80219694 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9278 80219698 00000007 */  srav      $zero, $zero, $zero
/* 4F927C 8021969C 00000043 */  sra       $zero, $zero, 1
/* 4F9280 802196A0 00000003 */  sra       $zero, $zero, 0
/* 4F9284 802196A4 8026F230 */  lb        $a2, -0xdd0($at)
/* 4F9288 802196A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F928C 802196AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9290 802196B0 00000010 */  mfhi      $zero
/* 4F9294 802196B4 00000002 */  srl       $zero, $zero, 0
/* 4F9298 802196B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F929C 802196BC 00002000 */  sll       $a0, $zero, 0
/* 4F92A0 802196C0 00000024 */  and       $zero, $zero, $zero
/* 4F92A4 802196C4 00000002 */  srl       $zero, $zero, 0
/* 4F92A8 802196C8 FBD3E280 */  bbit132   $fp, 0x13, .L802120CC
/* 4F92AC 802196CC 00000000 */   nop      
/* 4F92B0 802196D0 00000012 */  mflo      $zero
/* 4F92B4 802196D4 00000000 */  nop       
/* 4F92B8 802196D8 00000024 */  and       $zero, $zero, $zero
/* 4F92BC 802196DC 00000002 */  srl       $zero, $zero, 0
/* 4F92C0 802196E0 FBD3E280 */  bbit132   $fp, 0x13, .L802120E4
/* 4F92C4 802196E4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F92C8 802196E8 00000013 */  mtlo      $zero
/* 4F92CC 802196EC 00000000 */  nop       
/* 4F92D0 802196F0 00000023 */  negu      $zero, $zero
/* 4F92D4 802196F4 00000000 */  nop       
/* 4F92D8 802196F8 00000043 */  sra       $zero, $zero, 1
/* 4F92DC 802196FC 00000002 */  srl       $zero, $zero, 0
/* 4F92E0 80219700 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4F92E4 80219704 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F92E8 80219708 00000043 */  sra       $zero, $zero, 1
/* 4F92EC 8021970C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F92F0 80219710 8026A748 */  lb        $a2, -0x58b8($at)
/* 4F92F4 80219714 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F92F8 80219718 FFFFFFFD */  sd        $ra, -3($ra)
/* 4F92FC 8021971C FFFFFFF4 */  sd        $ra, -0xc($ra)
/* 4F9300 80219720 FFFFFFF1 */  sd        $ra, -0xf($ra)
/* 4F9304 80219724 00000043 */  sra       $zero, $zero, 1
/* 4F9308 80219728 00000003 */  sra       $zero, $zero, 0
/* 4F930C 8021972C 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F9310 80219730 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9314 80219734 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4F9318 80219738 00000043 */  sra       $zero, $zero, 1
/* 4F931C 8021973C 00000004 */  sllv      $zero, $zero, $zero
/* 4F9320 80219740 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F9324 80219744 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9328 80219748 00000001 */  movf      $zero, $zero, $fcc0
/* 4F932C 8021974C 002B0105 */  .byte     0x00, 0x2b, 0x01, 0x05
/* 4F9330 80219750 00000043 */  sra       $zero, $zero, 1
/* 4F9334 80219754 00000006 */  srlv      $zero, $zero, $zero
/* 4F9338 80219758 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F933C 8021975C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9340 80219760 00000008 */  jr        $zero
/* 4F9344 80219764 00000000 */   nop      
/* 4F9348 80219768 00000001 */  movf      $zero, $zero, $fcc0
/* 4F934C 8021976C 00000000 */  nop       
/* 4F9350 80219770 0000000A */  movz      $zero, $zero, $zero
/* 4F9354 80219774 00000002 */  srl       $zero, $zero, 0
/* 4F9358 80219778 FBD3E280 */  bbit132   $fp, 0x13, .L8021217C
/* 4F935C 8021977C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9360 80219780 00000043 */  sra       $zero, $zero, 1
/* 4F9364 80219784 00000008 */  jr        $zero
/* 4F9368 80219788 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F936C 8021978C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9370 80219790 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9374 80219794 08000000 */  j         .L80000000
/* 4F9378 80219798 00000000 */   nop      
/* 4F937C 8021979C 00000000 */  nop       
/* 4F9380 802197A0 00000000 */  nop       
/* 4F9384 802197A4 00000020 */  add       $zero, $zero, $zero
/* 4F9388 802197A8 00000002 */  srl       $zero, $zero, 0
/* 4F938C 802197AC 00000000 */  nop       
/* 4F9390 802197B0 00000013 */  mtlo      $zero
/* 4F9394 802197B4 00000000 */  nop       
/* 4F9398 802197B8 00000008 */  jr        $zero
/* 4F939C 802197BC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F93A0 802197C0 0000000A */  movz      $zero, $zero, $zero
/* 4F93A4 802197C4 00000043 */  sra       $zero, $zero, 1
/* 4F93A8 802197C8 00000003 */  sra       $zero, $zero, 0
/* 4F93AC 802197CC 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F93B0 802197D0 00000000 */  nop       
/* 4F93B4 802197D4 00000000 */  nop       
/* 4F93B8 802197D8 00000043 */  sra       $zero, $zero, 1
/* 4F93BC 802197DC 00000004 */  sllv      $zero, $zero, $zero
/* 4F93C0 802197E0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F93C4 802197E4 00000000 */  nop       
/* 4F93C8 802197E8 00000000 */  nop       
/* 4F93CC 802197EC 0003000C */  syscall   0xc00
/* 4F93D0 802197F0 00000043 */  sra       $zero, $zero, 1
/* 4F93D4 802197F4 00000003 */  sra       $zero, $zero, 0
/* 4F93D8 802197F8 8025385C */  lb        $a1, 0x385c($at)
/* 4F93DC 802197FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F93E0 80219800 000003E0 */  .byte     0x00, 0x00, 0x03, 0xe0
/* 4F93E4 80219804 00000043 */  sra       $zero, $zero, 1
/* 4F93E8 80219808 00000004 */  sllv      $zero, $zero, $zero
/* 4F93EC 8021980C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F93F0 80219810 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F93F4 80219814 00000001 */  movf      $zero, $zero, $fcc0
/* 4F93F8 80219818 002B0107 */  .byte     0x00, 0x2b, 0x01, 0x07
/* 4F93FC 8021981C 00000008 */  jr        $zero
/* 4F9400 80219820 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9404 80219824 00000015 */  dlsa      $zero, $zero, $zero, 1
/* 4F9408 80219828 00000043 */  sra       $zero, $zero, 1
/* 4F940C 8021982C 00000004 */  sllv      $zero, $zero, $zero
/* 4F9410 80219830 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F9414 80219834 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9418 80219838 00000001 */  movf      $zero, $zero, $fcc0
/* 4F941C 8021983C 002B0100 */  .byte     0x00, 0x2b, 0x01, 0x00
/* 4F9420 80219840 00000043 */  sra       $zero, $zero, 1
/* 4F9424 80219844 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9428 80219848 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F942C 8021984C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9430 80219850 00000000 */  nop       
/* 4F9434 80219854 00000000 */  nop       
/* 4F9438 80219858 0000014A */  .byte     0x00, 0x00, 0x01, 0x4a
/* 4F943C 8021985C 00000043 */  sra       $zero, $zero, 1
/* 4F9440 80219860 00000003 */  sra       $zero, $zero, 0
/* 4F9444 80219864 8025385C */  lb        $a1, 0x385c($at)
/* 4F9448 80219868 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F944C 8021986C 000003E0 */  .byte     0x00, 0x00, 0x03, 0xe0
/* 4F9450 80219870 00000043 */  sra       $zero, $zero, 1
/* 4F9454 80219874 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9458 80219878 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F945C 8021987C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9460 80219880 FFFFFFFD */  sd        $ra, -3($ra)
/* 4F9464 80219884 FFFFFFFE */  sd        $ra, -2($ra)
/* 4F9468 80219888 00000000 */  nop       
/* 4F946C 8021988C 00000043 */  sra       $zero, $zero, 1
/* 4F9470 80219890 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9474 80219894 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9478 80219898 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F947C 8021989C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9480 802198A0 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9484 802198A4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9488 802198A8 00000008 */  jr        $zero
/* 4F948C 802198AC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9490 802198B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9494 802198B4 00000043 */  sra       $zero, $zero, 1
/* 4F9498 802198B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F949C 802198BC 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F94A0 802198C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F94A4 802198C4 F24A7E1A */  scd       $t2, 0x7e1a($s2)
/* 4F94A8 802198C8 F24A7F4D */  scd       $t2, 0x7f4d($s2)
/* 4F94AC 802198CC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F94B0 802198D0 00000008 */  jr        $zero
/* 4F94B4 802198D4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F94B8 802198D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F94BC 802198DC 00000043 */  sra       $zero, $zero, 1
/* 4F94C0 802198E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F94C4 802198E4 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F94C8 802198E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F94CC 802198EC F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 4F94D0 802198F0 F24A7FB4 */  scd       $t2, 0x7fb4($s2)
/* 4F94D4 802198F4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F94D8 802198F8 00000008 */  jr        $zero
/* 4F94DC 802198FC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F94E0 80219900 00000001 */  movf      $zero, $zero, $fcc0
/* 4F94E4 80219904 00000043 */  sra       $zero, $zero, 1
/* 4F94E8 80219908 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F94EC 8021990C 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F94F0 80219910 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F94F4 80219914 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F94F8 80219918 F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F94FC 8021991C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9500 80219920 00000008 */  jr        $zero
/* 4F9504 80219924 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9508 80219928 00000001 */  movf      $zero, $zero, $fcc0
/* 4F950C 8021992C 00000043 */  sra       $zero, $zero, 1
/* 4F9510 80219930 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9514 80219934 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9518 80219938 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F951C 8021993C F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F9520 80219940 F24A8080 */  scd       $t2, -0x7f80($s2)
/* 4F9524 80219944 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9528 80219948 00000008 */  jr        $zero
/* 4F952C 8021994C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9530 80219950 00000002 */  srl       $zero, $zero, 0
/* 4F9534 80219954 00000043 */  sra       $zero, $zero, 1
/* 4F9538 80219958 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F953C 8021995C 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9540 80219960 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9544 80219964 F24A7CE7 */  scd       $t2, 0x7ce7($s2)
/* 4F9548 80219968 F24A80E7 */  scd       $t2, -0x7f19($s2)
/* 4F954C 8021996C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9550 80219970 00000008 */  jr        $zero
/* 4F9554 80219974 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9558 80219978 0000000A */  movz      $zero, $zero, $zero
/* 4F955C 8021997C 00000008 */  jr        $zero
/* 4F9560 80219980 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9564 80219984 00000002 */  srl       $zero, $zero, 0
/* 4F9568 80219988 00000043 */  sra       $zero, $zero, 1
/* 4F956C 8021998C 00000003 */  sra       $zero, $zero, 0
/* 4F9570 80219990 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F9574 80219994 00000000 */  nop       
/* 4F9578 80219998 00000001 */  movf      $zero, $zero, $fcc0
/* 4F957C 8021999C 00000043 */  sra       $zero, $zero, 1
/* 4F9580 802199A0 00000008 */  jr        $zero
/* 4F9584 802199A4 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4F9588 802199A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F958C 802199AC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9590 802199B0 08000000 */  j         .L80000000
/* 4F9594 802199B4 00000000 */   nop      
/* 4F9598 802199B8 00000000 */  nop       
/* 4F959C 802199BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F95A0 802199C0 00000020 */  add       $zero, $zero, $zero
/* 4F95A4 802199C4 00000043 */  sra       $zero, $zero, 1
/* 4F95A8 802199C8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F95AC 802199CC 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F95B0 802199D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F95B4 802199D4 00000000 */  nop       
/* 4F95B8 802199D8 00000000 */  nop       
/* 4F95BC 802199DC 00000000 */  nop       
/* 4F95C0 802199E0 00000043 */  sra       $zero, $zero, 1
/* 4F95C4 802199E4 00000004 */  sllv      $zero, $zero, $zero
/* 4F95C8 802199E8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F95CC 802199EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F95D0 802199F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F95D4 802199F4 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F95D8 802199F8 00000043 */  sra       $zero, $zero, 1
/* 4F95DC 802199FC 00000002 */  srl       $zero, $zero, 0
/* 4F95E0 80219A00 8024E61C */  lb        $a0, -0x19e4($at)
/* 4F95E4 80219A04 00000002 */  srl       $zero, $zero, 0
/* 4F95E8 80219A08 00000043 */  sra       $zero, $zero, 1
/* 4F95EC 80219A0C 00000003 */  sra       $zero, $zero, 0
/* 4F95F0 80219A10 8027DB3C */  lb        $a3, -0x24c4($at)
/* 4F95F4 80219A14 00000000 */  nop       
/* 4F95F8 80219A18 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F95FC 80219A1C 0000000B */  movn      $zero, $zero, $zero
/* 4F9600 80219A20 00000002 */  srl       $zero, $zero, 0
/* 4F9604 80219A24 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F9608 80219A28 00000000 */  nop       
/* 4F960C 80219A2C 00000043 */  sra       $zero, $zero, 1
/* 4F9610 80219A30 00000003 */  sra       $zero, $zero, 0
/* 4F9614 80219A34 8025385C */  lb        $a1, 0x385c($at)
/* 4F9618 80219A38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F961C 80219A3C 0000206D */  .byte     0x00, 0x00, 0x20, 0x6d
/* 4F9620 80219A40 00000043 */  sra       $zero, $zero, 1
/* 4F9624 80219A44 00000003 */  sra       $zero, $zero, 0
/* 4F9628 80219A48 8025385C */  lb        $a1, 0x385c($at)
/* 4F962C 80219A4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9630 80219A50 00000214 */  .byte     0x00, 0x00, 0x02, 0x14
/* 4F9634 80219A54 00000043 */  sra       $zero, $zero, 1
/* 4F9638 80219A58 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F963C 80219A5C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4F9640 80219A60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9644 80219A64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9648 80219A68 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F964C 80219A6C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9650 80219A70 00000027 */  not       $zero, $zero
/* 4F9654 80219A74 00000002 */  srl       $zero, $zero, 0
/* 4F9658 80219A78 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F965C 80219A7C 0000000A */  movz      $zero, $zero, $zero
/* 4F9660 80219A80 00000043 */  sra       $zero, $zero, 1
/* 4F9664 80219A84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9668 80219A88 80218000 */  lb        $at, -0x8000($at)
/* 4F966C 80219A8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9670 80219A90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9674 80219A94 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9678 80219A98 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F967C 80219A9C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F9680 80219AA0 00000000 */  nop       
/* 4F9684 80219AA4 00000008 */  jr        $zero
/* 4F9688 80219AA8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F968C 80219AAC 0000000F */  sync      
/* 4F9690 80219AB0 00000043 */  sra       $zero, $zero, 1
/* 4F9694 80219AB4 00000003 */  sra       $zero, $zero, 0
/* 4F9698 80219AB8 8025385C */  lb        $a1, 0x385c($at)
/* 4F969C 80219ABC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F96A0 80219AC0 0000025C */  .byte     0x00, 0x00, 0x02, 0x5c
/* 4F96A4 80219AC4 00000043 */  sra       $zero, $zero, 1
/* 4F96A8 80219AC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F96AC 80219ACC 802180B4 */  lb        $at, -0x7f4c($at)
/* 4F96B0 80219AD0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F96B4 80219AD4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F96B8 80219AD8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F96BC 80219ADC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F96C0 80219AE0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F96C4 80219AE4 00000000 */  nop       
/* 4F96C8 80219AE8 00000027 */  not       $zero, $zero
/* 4F96CC 80219AEC 00000002 */  srl       $zero, $zero, 0
/* 4F96D0 80219AF0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F96D4 80219AF4 00000014 */  dsllv     $zero, $zero, $zero
/* 4F96D8 80219AF8 00000027 */  not       $zero, $zero
/* 4F96DC 80219AFC 00000002 */  srl       $zero, $zero, 0
/* 4F96E0 80219B00 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F96E4 80219B04 00000014 */  dsllv     $zero, $zero, $zero
/* 4F96E8 80219B08 00000043 */  sra       $zero, $zero, 1
/* 4F96EC 80219B0C 0000000F */  sync      
/* 4F96F0 80219B10 802D829C */  lb        $t5, -0x7d64($at)
/* 4F96F4 80219B14 00000040 */  ssnop     
/* 4F96F8 80219B18 00000000 */  nop       
/* 4F96FC 80219B1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9700 80219B20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9704 80219B24 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9708 80219B28 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F970C 80219B2C 00000000 */  nop       
/* 4F9710 80219B30 00000000 */  nop       
/* 4F9714 80219B34 00000000 */  nop       
/* 4F9718 80219B38 00000000 */  nop       
/* 4F971C 80219B3C 00000000 */  nop       
/* 4F9720 80219B40 00000000 */  nop       
/* 4F9724 80219B44 00000000 */  nop       
/* 4F9728 80219B48 00000000 */  nop       
/* 4F972C 80219B4C 00000043 */  sra       $zero, $zero, 1
/* 4F9730 80219B50 00000003 */  sra       $zero, $zero, 0
/* 4F9734 80219B54 8027C6A0 */  lb        $a3, -0x3960($at)
/* 4F9738 80219B58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F973C 80219B5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9740 80219B60 00000027 */  not       $zero, $zero
/* 4F9744 80219B64 00000002 */  srl       $zero, $zero, 0
/* 4F9748 80219B68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F974C 80219B6C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4F9750 80219B70 00000043 */  sra       $zero, $zero, 1
/* 4F9754 80219B74 00000003 */  sra       $zero, $zero, 0
/* 4F9758 80219B78 8027C5C8 */  lb        $a3, -0x3a38($at)
/* 4F975C 80219B7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9760 80219B80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9764 80219B84 00000013 */  mtlo      $zero
/* 4F9768 80219B88 00000000 */  nop       
/* 4F976C 80219B8C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F9770 80219B90 00000000 */  nop       
/* 4F9774 80219B94 00000043 */  sra       $zero, $zero, 1
/* 4F9778 80219B98 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F977C 80219B9C 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9780 80219BA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9784 80219BA4 F24A80E7 */  scd       $t2, -0x7f19($s2)
/* 4F9788 80219BA8 F24A7CE7 */  scd       $t2, 0x7ce7($s2)
/* 4F978C 80219BAC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9790 80219BB0 00000043 */  sra       $zero, $zero, 1
/* 4F9794 80219BB4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9798 80219BB8 8026C4AC */  lb        $a2, -0x3b54($at)
/* 4F979C 80219BBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F97A0 80219BC0 00000000 */  nop       
/* 4F97A4 80219BC4 0000000A */  movz      $zero, $zero, $zero
/* 4F97A8 80219BC8 00000000 */  nop       
/* 4F97AC 80219BCC 00000008 */  jr        $zero
/* 4F97B0 80219BD0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F97B4 80219BD4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F97B8 80219BD8 00000043 */  sra       $zero, $zero, 1
/* 4F97BC 80219BDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F97C0 80219BE0 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F97C4 80219BE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F97C8 80219BE8 00000000 */  nop       
/* 4F97CC 80219BEC 00000000 */  nop       
/* 4F97D0 80219BF0 0000014A */  .byte     0x00, 0x00, 0x01, 0x4a
/* 4F97D4 80219BF4 00000008 */  jr        $zero
/* 4F97D8 80219BF8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F97DC 80219BFC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F97E0 80219C00 00000043 */  sra       $zero, $zero, 1
/* 4F97E4 80219C04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F97E8 80219C08 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F97EC 80219C0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F97F0 80219C10 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F97F4 80219C14 F24A8080 */  scd       $t2, -0x7f80($s2)
/* 4F97F8 80219C18 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F97FC 80219C1C 00000043 */  sra       $zero, $zero, 1
/* 4F9800 80219C20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9804 80219C24 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9808 80219C28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F980C 80219C2C 00000000 */  nop       
/* 4F9810 80219C30 00000000 */  nop       
/* 4F9814 80219C34 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 4F9818 80219C38 00000008 */  jr        $zero
/* 4F981C 80219C3C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9820 80219C40 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9824 80219C44 00000043 */  sra       $zero, $zero, 1
/* 4F9828 80219C48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F982C 80219C4C 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9830 80219C50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9834 80219C54 00000000 */  nop       
/* 4F9838 80219C58 00000000 */  nop       
/* 4F983C 80219C5C 0000010E */  .byte     0x00, 0x00, 0x01, 0x0e
/* 4F9840 80219C60 00000008 */  jr        $zero
/* 4F9844 80219C64 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9848 80219C68 00000001 */  movf      $zero, $zero, $fcc0
/* 4F984C 80219C6C 00000043 */  sra       $zero, $zero, 1
/* 4F9850 80219C70 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9854 80219C74 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9858 80219C78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F985C 80219C7C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9860 80219C80 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F9864 80219C84 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9868 80219C88 00000043 */  sra       $zero, $zero, 1
/* 4F986C 80219C8C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9870 80219C90 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9874 80219C94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9878 80219C98 00000000 */  nop       
/* 4F987C 80219C9C 00000000 */  nop       
/* 4F9880 80219CA0 000000F0 */  tge       $zero, $zero, 3
/* 4F9884 80219CA4 00000008 */  jr        $zero
/* 4F9888 80219CA8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F988C 80219CAC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9890 80219CB0 00000043 */  sra       $zero, $zero, 1
/* 4F9894 80219CB4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9898 80219CB8 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F989C 80219CBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F98A0 80219CC0 00000000 */  nop       
/* 4F98A4 80219CC4 00000000 */  nop       
/* 4F98A8 80219CC8 000000D2 */  .byte     0x00, 0x00, 0x00, 0xd2
/* 4F98AC 80219CCC 00000008 */  jr        $zero
/* 4F98B0 80219CD0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F98B4 80219CD4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F98B8 80219CD8 00000043 */  sra       $zero, $zero, 1
/* 4F98BC 80219CDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F98C0 80219CE0 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F98C4 80219CE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F98C8 80219CE8 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F98CC 80219CEC F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F98D0 80219CF0 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F98D4 80219CF4 00000043 */  sra       $zero, $zero, 1
/* 4F98D8 80219CF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F98DC 80219CFC 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F98E0 80219D00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F98E4 80219D04 00000000 */  nop       
/* 4F98E8 80219D08 00000000 */  nop       
/* 4F98EC 80219D0C 000000B4 */  teq       $zero, $zero, 2
/* 4F98F0 80219D10 00000008 */  jr        $zero
/* 4F98F4 80219D14 00000001 */   movf     $zero, $zero, $fcc0
/* 4F98F8 80219D18 00000002 */  srl       $zero, $zero, 0
/* 4F98FC 80219D1C 00000043 */  sra       $zero, $zero, 1
/* 4F9900 80219D20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9904 80219D24 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9908 80219D28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F990C 80219D2C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9910 80219D30 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 4F9914 80219D34 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9918 80219D38 00000008 */  jr        $zero
/* 4F991C 80219D3C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9920 80219D40 00000002 */  srl       $zero, $zero, 0
/* 4F9924 80219D44 00000043 */  sra       $zero, $zero, 1
/* 4F9928 80219D48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F992C 80219D4C 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9930 80219D50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9934 80219D54 F24A7F4D */  scd       $t2, 0x7f4d($s2)
/* 4F9938 80219D58 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F993C 80219D5C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9940 80219D60 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F9944 80219D64 00000000 */  nop       
/* 4F9948 80219D68 00000043 */  sra       $zero, $zero, 1
/* 4F994C 80219D6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9950 80219D70 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F9954 80219D74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9958 80219D78 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F995C 80219D7C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9960 80219D80 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9964 80219D84 00000027 */  not       $zero, $zero
/* 4F9968 80219D88 00000002 */  srl       $zero, $zero, 0
/* 4F996C 80219D8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9970 80219D90 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4F9974 80219D94 00000024 */  and       $zero, $zero, $zero
/* 4F9978 80219D98 00000002 */  srl       $zero, $zero, 0
/* 4F997C 80219D9C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9980 80219DA0 00000000 */  nop       
/* 4F9984 80219DA4 00000043 */  sra       $zero, $zero, 1
/* 4F9988 80219DA8 00000003 */  sra       $zero, $zero, 0
/* 4F998C 80219DAC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F9990 80219DB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9994 80219DB4 F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F9998 80219DB8 00000043 */  sra       $zero, $zero, 1
/* 4F999C 80219DBC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F99A0 80219DC0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F99A4 80219DC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F99A8 80219DC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F99AC 80219DCC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F99B0 80219DD0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F99B4 80219DD4 00000043 */  sra       $zero, $zero, 1
/* 4F99B8 80219DD8 00000006 */  srlv      $zero, $zero, $zero
/* 4F99BC 80219DDC 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F99C0 80219DE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F99C4 80219DE4 0000000A */  movz      $zero, $zero, $zero
/* 4F99C8 80219DE8 00000000 */  nop       
/* 4F99CC 80219DEC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F99D0 80219DF0 00000000 */  nop       
/* 4F99D4 80219DF4 00000043 */  sra       $zero, $zero, 1
/* 4F99D8 80219DF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F99DC 80219DFC 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F99E0 80219E00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F99E4 80219E04 F24A801A */  scd       $t2, -0x7fe6($s2)
/* 4F99E8 80219E08 F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 4F99EC 80219E0C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F99F0 80219E10 00000008 */  jr        $zero
/* 4F99F4 80219E14 00000001 */   movf     $zero, $zero, $fcc0
/* 4F99F8 80219E18 00000001 */  movf      $zero, $zero, $fcc0
/* 4F99FC 80219E1C 00000056 */  drotrv    $zero, $zero, $zero
/* 4F9A00 80219E20 00000000 */  nop       
/* 4F9A04 80219E24 00000008 */  jr        $zero
/* 4F9A08 80219E28 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9A0C 80219E2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9A10 80219E30 00000043 */  sra       $zero, $zero, 1
/* 4F9A14 80219E34 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9A18 80219E38 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9A1C 80219E3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9A20 80219E40 F24A7F4D */  scd       $t2, 0x7f4d($s2)
/* 4F9A24 80219E44 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 4F9A28 80219E48 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9A2C 80219E4C 00000043 */  sra       $zero, $zero, 1
/* 4F9A30 80219E50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9A34 80219E54 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9A38 80219E58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9A3C 80219E5C 00000000 */  nop       
/* 4F9A40 80219E60 00000000 */  nop       
/* 4F9A44 80219E64 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4F9A48 80219E68 00000008 */  jr        $zero
/* 4F9A4C 80219E6C 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9A50 80219E70 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9A54 80219E74 00000043 */  sra       $zero, $zero, 1
/* 4F9A58 80219E78 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9A5C 80219E7C 8026C904 */  lb        $a2, -0x36fc($at)
/* 4F9A60 80219E80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9A64 80219E84 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9A68 80219E88 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9A6C 80219E8C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4F9A70 80219E90 00000043 */  sra       $zero, $zero, 1
/* 4F9A74 80219E94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9A78 80219E98 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9A7C 80219E9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9A80 80219EA0 00000000 */  nop       
/* 4F9A84 80219EA4 00000000 */  nop       
/* 4F9A88 80219EA8 00000078 */  dsll      $zero, $zero, 1
/* 4F9A8C 80219EAC 00000008 */  jr        $zero
/* 4F9A90 80219EB0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9A94 80219EB4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9A98 80219EB8 00000043 */  sra       $zero, $zero, 1
/* 4F9A9C 80219EBC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9AA0 80219EC0 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9AA4 80219EC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9AA8 80219EC8 00000000 */  nop       
/* 4F9AAC 80219ECC 00000000 */  nop       
/* 4F9AB0 80219ED0 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4F9AB4 80219ED4 00000008 */  jr        $zero
/* 4F9AB8 80219ED8 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9ABC 80219EDC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9AC0 80219EE0 00000043 */  sra       $zero, $zero, 1
/* 4F9AC4 80219EE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9AC8 80219EE8 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9ACC 80219EEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9AD0 80219EF0 00000000 */  nop       
/* 4F9AD4 80219EF4 00000000 */  nop       
/* 4F9AD8 80219EF8 0000003C */  dsll32    $zero, $zero, 0
/* 4F9ADC 80219EFC 00000008 */  jr        $zero
/* 4F9AE0 80219F00 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9AE4 80219F04 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9AE8 80219F08 00000043 */  sra       $zero, $zero, 1
/* 4F9AEC 80219F0C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9AF0 80219F10 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9AF4 80219F14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9AF8 80219F18 00000000 */  nop       
/* 4F9AFC 80219F1C 00000000 */  nop       
/* 4F9B00 80219F20 0000001E */  ddiv      $zero, $zero, $zero
/* 4F9B04 80219F24 00000008 */  jr        $zero
/* 4F9B08 80219F28 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9B0C 80219F2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9B10 80219F30 00000043 */  sra       $zero, $zero, 1
/* 4F9B14 80219F34 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9B18 80219F38 8026C3AC */  lb        $a2, -0x3c54($at)
/* 4F9B1C 80219F3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9B20 80219F40 00000000 */  nop       
/* 4F9B24 80219F44 00000000 */  nop       
/* 4F9B28 80219F48 00000000 */  nop       
/* 4F9B2C 80219F4C 00000043 */  sra       $zero, $zero, 1
/* 4F9B30 80219F50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9B34 80219F54 8026C4AC */  lb        $a2, -0x3b54($at)
/* 4F9B38 80219F58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9B3C 80219F5C 00000000 */  nop       
/* 4F9B40 80219F60 00000000 */  nop       
/* 4F9B44 80219F64 00000000 */  nop       
/* 4F9B48 80219F68 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4F9B4C 80219F6C 00000000 */  nop       
/* 4F9B50 80219F70 00000043 */  sra       $zero, $zero, 1
/* 4F9B54 80219F74 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9B58 80219F78 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F9B5C 80219F7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9B60 80219F80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9B64 80219F84 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9B68 80219F88 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9B6C 80219F8C 00000027 */  not       $zero, $zero
/* 4F9B70 80219F90 00000002 */  srl       $zero, $zero, 0
/* 4F9B74 80219F94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9B78 80219F98 0000001E */  ddiv      $zero, $zero, $zero
/* 4F9B7C 80219F9C 00000043 */  sra       $zero, $zero, 1
/* 4F9B80 80219FA0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9B84 80219FA4 8026A510 */  lb        $a2, -0x5af0($at)
/* 4F9B88 80219FA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9B8C 80219FAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9B90 80219FB0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9B94 80219FB4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9B98 80219FB8 00000043 */  sra       $zero, $zero, 1
/* 4F9B9C 80219FBC 00000006 */  srlv      $zero, $zero, $zero
/* 4F9BA0 80219FC0 80278D08 */  lb        $a3, -0x72f8($at)
/* 4F9BA4 80219FC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9BA8 80219FC8 00000008 */  jr        $zero
/* 4F9BAC 80219FCC 00000000 */   nop      
/* 4F9BB0 80219FD0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9BB4 80219FD4 00000000 */  nop       
/* 4F9BB8 80219FD8 00000008 */  jr        $zero
/* 4F9BBC 80219FDC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9BC0 80219FE0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9BC4 80219FE4 00000043 */  sra       $zero, $zero, 1
/* 4F9BC8 80219FE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9BCC 80219FEC 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4F9BD0 80219FF0 00000043 */  sra       $zero, $zero, 1
/* 4F9BD4 80219FF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9BD8 80219FF8 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4F9BDC 80219FFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9BE0 8021A000 00000000 */  nop       
/* 4F9BE4 8021A004 00000000 */  nop       
/* 4F9BE8 8021A008 00000000 */  nop       
/* 4F9BEC 8021A00C 00000043 */  sra       $zero, $zero, 1
/* 4F9BF0 8021A010 00000004 */  sllv      $zero, $zero, $zero
/* 4F9BF4 8021A014 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F9BF8 8021A018 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9BFC 8021A01C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9C00 8021A020 002B0103 */  .byte     0x00, 0x2b, 0x01, 0x03
/* 4F9C04 8021A024 00000043 */  sra       $zero, $zero, 1
/* 4F9C08 8021A028 00000002 */  srl       $zero, $zero, 0
/* 4F9C0C 8021A02C 80269EC4 */  lb        $a2, -0x613c($at)
/* 4F9C10 8021A030 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9C14 8021A034 00000043 */  sra       $zero, $zero, 1
/* 4F9C18 8021A038 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4F9C1C 8021A03C 8026A820 */  lb        $a2, -0x57e0($at)
/* 4F9C20 8021A040 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9C24 8021A044 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9C28 8021A048 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4F9C2C 8021A04C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4F9C30 8021A050 00000043 */  sra       $zero, $zero, 1
/* 4F9C34 8021A054 00000003 */  sra       $zero, $zero, 0
/* 4F9C38 8021A058 8026B654 */  lb        $a2, -0x49ac($at)
/* 4F9C3C 8021A05C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9C40 8021A060 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4F9C44 8021A064 00000043 */  sra       $zero, $zero, 1
/* 4F9C48 8021A068 00000003 */  sra       $zero, $zero, 0
/* 4F9C4C 8021A06C 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4F9C50 8021A070 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9C54 8021A074 F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 4F9C58 8021A078 00000046 */  rotrv     $zero, $zero, $zero
/* 4F9C5C 8021A07C 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9C60 8021A080 8029C12C */  lb        $t1, -0x3ed4($at)
/* 4F9C64 8021A084 00000043 */  sra       $zero, $zero, 1
/* 4F9C68 8021A088 00000004 */  sllv      $zero, $zero, $zero
/* 4F9C6C 8021A08C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4F9C70 8021A090 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9C74 8021A094 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9C78 8021A098 002B0101 */  .byte     0x00, 0x2b, 0x01, 0x01
/* 4F9C7C 8021A09C 00000043 */  sra       $zero, $zero, 1
/* 4F9C80 8021A0A0 00000003 */  sra       $zero, $zero, 0
/* 4F9C84 8021A0A4 80278B4C */  lb        $a3, -0x74b4($at)
/* 4F9C88 8021A0A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9C8C 8021A0AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9C90 8021A0B0 00000043 */  sra       $zero, $zero, 1
/* 4F9C94 8021A0B4 00000003 */  sra       $zero, $zero, 0
/* 4F9C98 8021A0B8 8026F0EC */  lb        $a2, -0xf14($at)
/* 4F9C9C 8021A0BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9CA0 8021A0C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9CA4 8021A0C4 00000002 */  srl       $zero, $zero, 0
/* 4F9CA8 8021A0C8 00000000 */  nop       
/* 4F9CAC 8021A0CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9CB0 8021A0D0 00000000 */  nop       
/* 4F9CB4 8021A0D4 00000024 */  and       $zero, $zero, $zero
/* 4F9CB8 8021A0D8 00000002 */  srl       $zero, $zero, 0
/* 4F9CBC 8021A0DC FBD3E281 */  bbit132   $fp, 0x13, .L80212AE4
/* 4F9CC0 8021A0E0 00000000 */   nop      
/* 4F9CC4 8021A0E4 00000024 */  and       $zero, $zero, $zero
/* 4F9CC8 8021A0E8 00000002 */  srl       $zero, $zero, 0
/* 4F9CCC 8021A0EC FBD3E282 */  bbit132   $fp, 0x13, .L80212AF8
/* 4F9CD0 8021A0F0 00000000 */   nop      
/* 4F9CD4 8021A0F4 00000024 */  and       $zero, $zero, $zero
/* 4F9CD8 8021A0F8 00000002 */  srl       $zero, $zero, 0
/* 4F9CDC 8021A0FC FBD3E283 */  bbit132   $fp, 0x13, .L80212B0C
/* 4F9CE0 8021A100 00000000 */   nop      
/* 4F9CE4 8021A104 00000024 */  and       $zero, $zero, $zero
/* 4F9CE8 8021A108 00000002 */  srl       $zero, $zero, 0
/* 4F9CEC 8021A10C FBD3E284 */  bbit132   $fp, 0x13, .L80212B20
/* 4F9CF0 8021A110 00000000 */   nop      
/* 4F9CF4 8021A114 00000043 */  sra       $zero, $zero, 1
/* 4F9CF8 8021A118 00000002 */  srl       $zero, $zero, 0
/* 4F9CFC 8021A11C 8026E310 */  lb        $a2, -0x1cf0($at)
/* 4F9D00 8021A120 00008002 */  srl       $s0, $zero, 0
/* 4F9D04 8021A124 00000043 */  sra       $zero, $zero, 1
/* 4F9D08 8021A128 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9D0C 8021A12C 8026E354 */  lb        $a2, -0x1cac($at)
/* 4F9D10 8021A130 00000003 */  sra       $zero, $zero, 0
/* 4F9D14 8021A134 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9D18 8021A138 00000000 */  nop       
/* 4F9D1C 8021A13C 00000043 */  sra       $zero, $zero, 1
/* 4F9D20 8021A140 00000003 */  sra       $zero, $zero, 0
/* 4F9D24 8021A144 8026E8AC */  lb        $a2, -0x1754($at)
/* 4F9D28 8021A148 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9D2C 8021A14C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F9D30 8021A150 00000043 */  sra       $zero, $zero, 1
/* 4F9D34 8021A154 00000003 */  sra       $zero, $zero, 0
/* 4F9D38 8021A158 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 4F9D3C 8021A15C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9D40 8021A160 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F9D44 8021A164 0000002B */  sltu      $zero, $zero, $zero
/* 4F9D48 8021A168 00000002 */  srl       $zero, $zero, 0
/* 4F9D4C 8021A16C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F9D50 8021A170 00000004 */  sllv      $zero, $zero, $zero
/* 4F9D54 8021A174 00000014 */  dsllv     $zero, $zero, $zero
/* 4F9D58 8021A178 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9D5C 8021A17C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4F9D60 8021A180 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9D64 8021A184 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9D68 8021A188 00000000 */  nop       
/* 4F9D6C 8021A18C 00000024 */  and       $zero, $zero, $zero
/* 4F9D70 8021A190 00000002 */  srl       $zero, $zero, 0
/* 4F9D74 8021A194 FBD3E281 */  bbit132   $fp, 0x13, .L80212B9C
/* 4F9D78 8021A198 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9D7C 8021A19C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9D80 8021A1A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9D84 8021A1A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9D88 8021A1A8 00000024 */  and       $zero, $zero, $zero
/* 4F9D8C 8021A1AC 00000002 */  srl       $zero, $zero, 0
/* 4F9D90 8021A1B0 FBD3E282 */  bbit132   $fp, 0x13, .L80212BBC
/* 4F9D94 8021A1B4 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9D98 8021A1B8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9D9C 8021A1BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9DA0 8021A1C0 00000002 */  srl       $zero, $zero, 0
/* 4F9DA4 8021A1C4 00000024 */  and       $zero, $zero, $zero
/* 4F9DA8 8021A1C8 00000002 */  srl       $zero, $zero, 0
/* 4F9DAC 8021A1CC FBD3E283 */  bbit132   $fp, 0x13, .L80212BDC
/* 4F9DB0 8021A1D0 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9DB4 8021A1D4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9DB8 8021A1D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9DBC 8021A1DC 00000003 */  sra       $zero, $zero, 0
/* 4F9DC0 8021A1E0 00000024 */  and       $zero, $zero, $zero
/* 4F9DC4 8021A1E4 00000002 */  srl       $zero, $zero, 0
/* 4F9DC8 8021A1E8 FBD3E284 */  bbit132   $fp, 0x13, .L80212BFC
/* 4F9DCC 8021A1EC 00000001 */   movf     $zero, $zero, $fcc0
/* 4F9DD0 8021A1F0 00000023 */  negu      $zero, $zero
/* 4F9DD4 8021A1F4 00000000 */  nop       
/* 4F9DD8 8021A1F8 00000043 */  sra       $zero, $zero, 1
/* 4F9DDC 8021A1FC 00000003 */  sra       $zero, $zero, 0
/* 4F9DE0 8021A200 8026E414 */  lb        $a2, -0x1bec($at)
/* 4F9DE4 8021A204 00000000 */  nop       
/* 4F9DE8 8021A208 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9DEC 8021A20C 0000000B */  movn      $zero, $zero, $zero
/* 4F9DF0 8021A210 00000002 */  srl       $zero, $zero, 0
/* 4F9DF4 8021A214 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9DF8 8021A218 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F9DFC 8021A21C 00000004 */  sllv      $zero, $zero, $zero
/* 4F9E00 8021A220 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9E04 8021A224 00000000 */  nop       
/* 4F9E08 8021A228 00000013 */  mtlo      $zero
/* 4F9E0C 8021A22C 00000000 */  nop       
/* 4F9E10 8021A230 00000024 */  and       $zero, $zero, $zero
/* 4F9E14 8021A234 00000002 */  srl       $zero, $zero, 0
/* 4F9E18 8021A238 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9E1C 8021A23C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F9E20 8021A240 00000024 */  and       $zero, $zero, $zero
/* 4F9E24 8021A244 00000002 */  srl       $zero, $zero, 0
/* 4F9E28 8021A248 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F9E2C 8021A24C FFFFFFFF */  sd        $ra, -1($ra)
/* 4F9E30 8021A250 00000043 */  sra       $zero, $zero, 1
/* 4F9E34 8021A254 00000003 */  sra       $zero, $zero, 0
/* 4F9E38 8021A258 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 4F9E3C 8021A25C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4F9E40 8021A260 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9E44 8021A264 00000014 */  dsllv     $zero, $zero, $zero
/* 4F9E48 8021A268 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9E4C 8021A26C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9E50 8021A270 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9E54 8021A274 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9E58 8021A278 00000000 */  nop       
/* 4F9E5C 8021A27C 0000000A */  movz      $zero, $zero, $zero
/* 4F9E60 8021A280 00000002 */  srl       $zero, $zero, 0
/* 4F9E64 8021A284 FBD3E282 */  bbit132   $fp, 0x13, .L80212C90
/* 4F9E68 8021A288 00000000 */   nop      
/* 4F9E6C 8021A28C 00000024 */  and       $zero, $zero, $zero
/* 4F9E70 8021A290 00000002 */  srl       $zero, $zero, 0
/* 4F9E74 8021A294 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9E78 8021A298 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9E7C 8021A29C 00000013 */  mtlo      $zero
/* 4F9E80 8021A2A0 00000000 */  nop       
/* 4F9E84 8021A2A4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9E88 8021A2A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9E8C 8021A2AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9E90 8021A2B0 0000000A */  movz      $zero, $zero, $zero
/* 4F9E94 8021A2B4 00000002 */  srl       $zero, $zero, 0
/* 4F9E98 8021A2B8 FBD3E281 */  bbit132   $fp, 0x13, .L80212CC0
/* 4F9E9C 8021A2BC 00000000 */   nop      
/* 4F9EA0 8021A2C0 00000024 */  and       $zero, $zero, $zero
/* 4F9EA4 8021A2C4 00000002 */  srl       $zero, $zero, 0
/* 4F9EA8 8021A2C8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9EAC 8021A2CC 00000000 */  nop       
/* 4F9EB0 8021A2D0 00000013 */  mtlo      $zero
/* 4F9EB4 8021A2D4 00000000 */  nop       
/* 4F9EB8 8021A2D8 0000000A */  movz      $zero, $zero, $zero
/* 4F9EBC 8021A2DC 00000002 */  srl       $zero, $zero, 0
/* 4F9EC0 8021A2E0 FBD3E283 */  bbit132   $fp, 0x13, .L80212CF0
/* 4F9EC4 8021A2E4 00000000 */   nop      
/* 4F9EC8 8021A2E8 0000000A */  movz      $zero, $zero, $zero
/* 4F9ECC 8021A2EC 00000002 */  srl       $zero, $zero, 0
/* 4F9ED0 8021A2F0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9ED4 8021A2F4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F9ED8 8021A2F8 00000024 */  and       $zero, $zero, $zero
/* 4F9EDC 8021A2FC 00000002 */  srl       $zero, $zero, 0
/* 4F9EE0 8021A300 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9EE4 8021A304 00000002 */  srl       $zero, $zero, 0
/* 4F9EE8 8021A308 00000012 */  mflo      $zero
/* 4F9EEC 8021A30C 00000000 */  nop       
/* 4F9EF0 8021A310 00000024 */  and       $zero, $zero, $zero
/* 4F9EF4 8021A314 00000002 */  srl       $zero, $zero, 0
/* 4F9EF8 8021A318 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F9EFC 8021A31C 00000002 */  srl       $zero, $zero, 0
/* 4F9F00 8021A320 00000013 */  mtlo      $zero
/* 4F9F04 8021A324 00000000 */  nop       
/* 4F9F08 8021A328 00000013 */  mtlo      $zero
/* 4F9F0C 8021A32C 00000000 */  nop       
/* 4F9F10 8021A330 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9F14 8021A334 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9F18 8021A338 00000002 */  srl       $zero, $zero, 0
/* 4F9F1C 8021A33C 0000000A */  movz      $zero, $zero, $zero
/* 4F9F20 8021A340 00000002 */  srl       $zero, $zero, 0
/* 4F9F24 8021A344 FBD3E282 */  bbit132   $fp, 0x13, .L80212D50
/* 4F9F28 8021A348 00000000 */   nop      
/* 4F9F2C 8021A34C 00000024 */  and       $zero, $zero, $zero
/* 4F9F30 8021A350 00000002 */  srl       $zero, $zero, 0
/* 4F9F34 8021A354 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9F38 8021A358 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9F3C 8021A35C 00000013 */  mtlo      $zero
/* 4F9F40 8021A360 00000000 */  nop       
/* 4F9F44 8021A364 0000000A */  movz      $zero, $zero, $zero
/* 4F9F48 8021A368 00000002 */  srl       $zero, $zero, 0
/* 4F9F4C 8021A36C FBD3E284 */  bbit132   $fp, 0x13, .L80212D80
/* 4F9F50 8021A370 00000000 */   nop      
/* 4F9F54 8021A374 0000000A */  movz      $zero, $zero, $zero
/* 4F9F58 8021A378 00000002 */  srl       $zero, $zero, 0
/* 4F9F5C 8021A37C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9F60 8021A380 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F9F64 8021A384 00000024 */  and       $zero, $zero, $zero
/* 4F9F68 8021A388 00000002 */  srl       $zero, $zero, 0
/* 4F9F6C 8021A38C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9F70 8021A390 00000003 */  sra       $zero, $zero, 0
/* 4F9F74 8021A394 00000012 */  mflo      $zero
/* 4F9F78 8021A398 00000000 */  nop       
/* 4F9F7C 8021A39C 00000024 */  and       $zero, $zero, $zero
/* 4F9F80 8021A3A0 00000002 */  srl       $zero, $zero, 0
/* 4F9F84 8021A3A4 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F9F88 8021A3A8 00000003 */  sra       $zero, $zero, 0
/* 4F9F8C 8021A3AC 00000013 */  mtlo      $zero
/* 4F9F90 8021A3B0 00000000 */  nop       
/* 4F9F94 8021A3B4 00000013 */  mtlo      $zero
/* 4F9F98 8021A3B8 00000000 */  nop       
/* 4F9F9C 8021A3BC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4F9FA0 8021A3C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4F9FA4 8021A3C4 00000003 */  sra       $zero, $zero, 0
/* 4F9FA8 8021A3C8 0000000A */  movz      $zero, $zero, $zero
/* 4F9FAC 8021A3CC 00000002 */  srl       $zero, $zero, 0
/* 4F9FB0 8021A3D0 FBD3E283 */  bbit132   $fp, 0x13, .L80212DE0
/* 4F9FB4 8021A3D4 00000000 */   nop      
/* 4F9FB8 8021A3D8 00000024 */  and       $zero, $zero, $zero
/* 4F9FBC 8021A3DC 00000002 */  srl       $zero, $zero, 0
/* 4F9FC0 8021A3E0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4F9FC4 8021A3E4 00000002 */  srl       $zero, $zero, 0
/* 4F9FC8 8021A3E8 00000013 */  mtlo      $zero
/* 4F9FCC 8021A3EC 00000000 */  nop       
/* 4F9FD0 8021A3F0 00000023 */  negu      $zero, $zero
/* 4F9FD4 8021A3F4 00000000 */  nop       
/* 4F9FD8 8021A3F8 0000000B */  movn      $zero, $zero, $zero
/* 4F9FDC 8021A3FC 00000002 */  srl       $zero, $zero, 0
/* 4F9FE0 8021A400 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4F9FE4 8021A404 FFFFFFFF */  sd        $ra, -1($ra)
/* 4F9FE8 8021A408 00000043 */  sra       $zero, $zero, 1
/* 4F9FEC 8021A40C 00000003 */  sra       $zero, $zero, 0
/* 4F9FF0 8021A410 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4F9FF4 8021A414 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 4F9FF8 8021A418 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4F9FFC 8021A41C 0000000C */  syscall   
/* 4FA000 8021A420 00000002 */  srl       $zero, $zero, 0
/* 4FA004 8021A424 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA008 8021A428 000001F4 */  teq       $zero, $zero, 7
/* 4FA00C 8021A42C 00000024 */  and       $zero, $zero, $zero
/* 4FA010 8021A430 00000002 */  srl       $zero, $zero, 0
/* 4FA014 8021A434 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FA018 8021A438 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FA01C 8021A43C 00000013 */  mtlo      $zero
/* 4FA020 8021A440 00000000 */  nop       
/* 4FA024 8021A444 00000013 */  mtlo      $zero
/* 4FA028 8021A448 00000000 */  nop       
/* 4FA02C 8021A44C 00000002 */  srl       $zero, $zero, 0
/* 4FA030 8021A450 00000000 */  nop       
/* 4FA034 8021A454 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA038 8021A458 00000000 */  nop       
/* 4FA03C 8021A45C 00000024 */  and       $zero, $zero, $zero
/* 4FA040 8021A460 00000002 */  srl       $zero, $zero, 0
/* 4FA044 8021A464 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FA048 8021A468 00000000 */  nop       
/* 4FA04C 8021A46C 00000043 */  sra       $zero, $zero, 1
/* 4FA050 8021A470 00000002 */  srl       $zero, $zero, 0
/* 4FA054 8021A474 8026E310 */  lb        $a2, -0x1cf0($at)
/* 4FA058 8021A478 00008002 */  srl       $s0, $zero, 0
/* 4FA05C 8021A47C 00000043 */  sra       $zero, $zero, 1
/* 4FA060 8021A480 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA064 8021A484 8026E354 */  lb        $a2, -0x1cac($at)
/* 4FA068 8021A488 00000003 */  sra       $zero, $zero, 0
/* 4FA06C 8021A48C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA070 8021A490 00000000 */  nop       
/* 4FA074 8021A494 00000043 */  sra       $zero, $zero, 1
/* 4FA078 8021A498 00000003 */  sra       $zero, $zero, 0
/* 4FA07C 8021A49C 8026E8AC */  lb        $a2, -0x1754($at)
/* 4FA080 8021A4A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA084 8021A4A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FA088 8021A4A8 00000043 */  sra       $zero, $zero, 1
/* 4FA08C 8021A4AC 00000003 */  sra       $zero, $zero, 0
/* 4FA090 8021A4B0 8027DA68 */  lb        $a3, -0x2598($at)
/* 4FA094 8021A4B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA098 8021A4B8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FA09C 8021A4BC 00000014 */  dsllv     $zero, $zero, $zero
/* 4FA0A0 8021A4C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA0A4 8021A4C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FA0A8 8021A4C8 0000001D */  dmultu    $zero, $zero
/* 4FA0AC 8021A4CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA0B0 8021A4D0 0000001A */  div       $zero, $zero, $zero
/* 4FA0B4 8021A4D4 0000001D */  dmultu    $zero, $zero
/* 4FA0B8 8021A4D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA0BC 8021A4DC 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4FA0C0 8021A4E0 00000043 */  sra       $zero, $zero, 1
/* 4FA0C4 8021A4E4 00000003 */  sra       $zero, $zero, 0
/* 4FA0C8 8021A4E8 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FA0CC 8021A4EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA0D0 8021A4F0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA0D4 8021A4F4 00000011 */  mthi      $zero
/* 4FA0D8 8021A4F8 00000002 */  srl       $zero, $zero, 0
/* 4FA0DC 8021A4FC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA0E0 8021A500 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4FA0E4 8021A504 00000043 */  sra       $zero, $zero, 1
/* 4FA0E8 8021A508 00000004 */  sllv      $zero, $zero, $zero
/* 4FA0EC 8021A50C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4FA0F0 8021A510 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA0F4 8021A514 00000000 */  nop       
/* 4FA0F8 8021A518 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA0FC 8021A51C 0000000B */  movn      $zero, $zero, $zero
/* 4FA100 8021A520 00000002 */  srl       $zero, $zero, 0
/* 4FA104 8021A524 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA108 8021A528 00000002 */  srl       $zero, $zero, 0
/* 4FA10C 8021A52C 00000027 */  not       $zero, $zero
/* 4FA110 8021A530 00000002 */  srl       $zero, $zero, 0
/* 4FA114 8021A534 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FA118 8021A538 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA11C 8021A53C 00000013 */  mtlo      $zero
/* 4FA120 8021A540 00000000 */  nop       
/* 4FA124 8021A544 00000013 */  mtlo      $zero
/* 4FA128 8021A548 00000000 */  nop       
/* 4FA12C 8021A54C 00000020 */  add       $zero, $zero, $zero
/* 4FA130 8021A550 00000000 */  nop       
/* 4FA134 8021A554 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA138 8021A558 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA13C 8021A55C 0000002A */  slt       $zero, $zero, $zero
/* 4FA140 8021A560 00000043 */  sra       $zero, $zero, 1
/* 4FA144 8021A564 00000003 */  sra       $zero, $zero, 0
/* 4FA148 8021A568 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FA14C 8021A56C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA150 8021A570 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA154 8021A574 00000011 */  mthi      $zero
/* 4FA158 8021A578 00000002 */  srl       $zero, $zero, 0
/* 4FA15C 8021A57C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA160 8021A580 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4FA164 8021A584 00000043 */  sra       $zero, $zero, 1
/* 4FA168 8021A588 00000004 */  sllv      $zero, $zero, $zero
/* 4FA16C 8021A58C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4FA170 8021A590 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA174 8021A594 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA178 8021A598 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA17C 8021A59C 0000000C */  syscall   
/* 4FA180 8021A5A0 00000002 */  srl       $zero, $zero, 0
/* 4FA184 8021A5A4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FA188 8021A5A8 00000002 */  srl       $zero, $zero, 0
/* 4FA18C 8021A5AC 00000027 */  not       $zero, $zero
/* 4FA190 8021A5B0 00000002 */  srl       $zero, $zero, 0
/* 4FA194 8021A5B4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FA198 8021A5B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA19C 8021A5BC 00000013 */  mtlo      $zero
/* 4FA1A0 8021A5C0 00000000 */  nop       
/* 4FA1A4 8021A5C4 00000013 */  mtlo      $zero
/* 4FA1A8 8021A5C8 00000000 */  nop       
/* 4FA1AC 8021A5CC 00000023 */  negu      $zero, $zero
/* 4FA1B0 8021A5D0 00000000 */  nop       
/* 4FA1B4 8021A5D4 00000043 */  sra       $zero, $zero, 1
/* 4FA1B8 8021A5D8 00000003 */  sra       $zero, $zero, 0
/* 4FA1BC 8021A5DC 8026E414 */  lb        $a2, -0x1bec($at)
/* 4FA1C0 8021A5E0 00000000 */  nop       
/* 4FA1C4 8021A5E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA1C8 8021A5E8 0000000B */  movn      $zero, $zero, $zero
/* 4FA1CC 8021A5EC 00000002 */  srl       $zero, $zero, 0
/* 4FA1D0 8021A5F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA1D4 8021A5F4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4FA1D8 8021A5F8 00000004 */  sllv      $zero, $zero, $zero
/* 4FA1DC 8021A5FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA1E0 8021A600 00000000 */  nop       
/* 4FA1E4 8021A604 00000013 */  mtlo      $zero
/* 4FA1E8 8021A608 00000000 */  nop       
/* 4FA1EC 8021A60C 00000002 */  srl       $zero, $zero, 0
/* 4FA1F0 8021A610 00000000 */  nop       
/* 4FA1F4 8021A614 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA1F8 8021A618 00000000 */  nop       
/* 4FA1FC 8021A61C 00000043 */  sra       $zero, $zero, 1
/* 4FA200 8021A620 00000002 */  srl       $zero, $zero, 0
/* 4FA204 8021A624 80269E28 */  lb        $a2, -0x61d8($at)
/* 4FA208 8021A628 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA20C 8021A62C 0000000A */  movz      $zero, $zero, $zero
/* 4FA210 8021A630 00000002 */  srl       $zero, $zero, 0
/* 4FA214 8021A634 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA218 8021A638 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA21C 8021A63C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA220 8021A640 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA224 8021A644 80219054 */  lb        $at, -0x6fac($at)
/* 4FA228 8021A648 00000002 */  srl       $zero, $zero, 0
/* 4FA22C 8021A64C 00000000 */  nop       
/* 4FA230 8021A650 00000013 */  mtlo      $zero
/* 4FA234 8021A654 00000000 */  nop       
/* 4FA238 8021A658 00000043 */  sra       $zero, $zero, 1
/* 4FA23C 8021A65C 00000004 */  sllv      $zero, $zero, $zero
/* 4FA240 8021A660 8026BFB4 */  lb        $a2, -0x404c($at)
/* 4FA244 8021A664 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA248 8021A668 00000000 */  nop       
/* 4FA24C 8021A66C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA250 8021A670 0000000A */  movz      $zero, $zero, $zero
/* 4FA254 8021A674 00000002 */  srl       $zero, $zero, 0
/* 4FA258 8021A678 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA25C 8021A67C 00000002 */  srl       $zero, $zero, 0
/* 4FA260 8021A680 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA264 8021A684 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA268 8021A688 80219054 */  lb        $at, -0x6fac($at)
/* 4FA26C 8021A68C 00000002 */  srl       $zero, $zero, 0
/* 4FA270 8021A690 00000000 */  nop       
/* 4FA274 8021A694 00000013 */  mtlo      $zero
/* 4FA278 8021A698 00000000 */  nop       
/* 4FA27C 8021A69C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA280 8021A6A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA284 8021A6A4 8021A0D4 */  lb        $at, -0x5f2c($at)
/* 4FA288 8021A6A8 0000000A */  movz      $zero, $zero, $zero
/* 4FA28C 8021A6AC 00000002 */  srl       $zero, $zero, 0
/* 4FA290 8021A6B0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FA294 8021A6B4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4FA298 8021A6B8 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA29C 8021A6BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA2A0 8021A6C0 80219054 */  lb        $at, -0x6fac($at)
/* 4FA2A4 8021A6C4 00000002 */  srl       $zero, $zero, 0
/* 4FA2A8 8021A6C8 00000000 */  nop       
/* 4FA2AC 8021A6CC 00000013 */  mtlo      $zero
/* 4FA2B0 8021A6D0 00000000 */  nop       
/* 4FA2B4 8021A6D4 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA2B8 8021A6D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA2BC 8021A6DC 8021A45C */  lb        $at, -0x5ba4($at)
/* 4FA2C0 8021A6E0 00000014 */  dsllv     $zero, $zero, $zero
/* 4FA2C4 8021A6E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA2C8 8021A6E8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FA2CC 8021A6EC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA2D0 8021A6F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA2D4 8021A6F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA2D8 8021A6F8 00000043 */  sra       $zero, $zero, 1
/* 4FA2DC 8021A6FC 00000003 */  sra       $zero, $zero, 0
/* 4FA2E0 8021A700 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4FA2E4 8021A704 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 4FA2E8 8021A708 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA2EC 8021A70C 0000000C */  syscall   
/* 4FA2F0 8021A710 00000002 */  srl       $zero, $zero, 0
/* 4FA2F4 8021A714 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA2F8 8021A718 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 4FA2FC 8021A71C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA300 8021A720 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA304 8021A724 80218C48 */  lb        $at, -0x73b8($at)
/* 4FA308 8021A728 00000002 */  srl       $zero, $zero, 0
/* 4FA30C 8021A72C 00000000 */  nop       
/* 4FA310 8021A730 00000013 */  mtlo      $zero
/* 4FA314 8021A734 00000000 */  nop       
/* 4FA318 8021A738 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA31C 8021A73C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA320 8021A740 00000002 */  srl       $zero, $zero, 0
/* 4FA324 8021A744 00000043 */  sra       $zero, $zero, 1
/* 4FA328 8021A748 00000003 */  sra       $zero, $zero, 0
/* 4FA32C 8021A74C 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4FA330 8021A750 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 4FA334 8021A754 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA338 8021A758 0000000C */  syscall   
/* 4FA33C 8021A75C 00000002 */  srl       $zero, $zero, 0
/* 4FA340 8021A760 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA344 8021A764 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 4FA348 8021A768 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA34C 8021A76C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA350 8021A770 80218C48 */  lb        $at, -0x73b8($at)
/* 4FA354 8021A774 00000002 */  srl       $zero, $zero, 0
/* 4FA358 8021A778 00000000 */  nop       
/* 4FA35C 8021A77C 00000013 */  mtlo      $zero
/* 4FA360 8021A780 00000000 */  nop       
/* 4FA364 8021A784 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA368 8021A788 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA36C 8021A78C 00000003 */  sra       $zero, $zero, 0
/* 4FA370 8021A790 00000043 */  sra       $zero, $zero, 1
/* 4FA374 8021A794 00000003 */  sra       $zero, $zero, 0
/* 4FA378 8021A798 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4FA37C 8021A79C 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 4FA380 8021A7A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA384 8021A7A4 0000000C */  syscall   
/* 4FA388 8021A7A8 00000002 */  srl       $zero, $zero, 0
/* 4FA38C 8021A7AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA390 8021A7B0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FA394 8021A7B4 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA398 8021A7B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA39C 8021A7BC 80218C48 */  lb        $at, -0x73b8($at)
/* 4FA3A0 8021A7C0 00000002 */  srl       $zero, $zero, 0
/* 4FA3A4 8021A7C4 00000000 */  nop       
/* 4FA3A8 8021A7C8 00000013 */  mtlo      $zero
/* 4FA3AC 8021A7CC 00000000 */  nop       
/* 4FA3B0 8021A7D0 00000023 */  negu      $zero, $zero
/* 4FA3B4 8021A7D4 00000000 */  nop       
/* 4FA3B8 8021A7D8 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA3BC 8021A7DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA3C0 8021A7E0 80219054 */  lb        $at, -0x6fac($at)
/* 4FA3C4 8021A7E4 00000002 */  srl       $zero, $zero, 0
/* 4FA3C8 8021A7E8 00000000 */  nop       
/* 4FA3CC 8021A7EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA3D0 8021A7F0 00000000 */  nop       
/* 4FA3D4 8021A7F4 00000000 */  nop       
/* 4FA3D8 8021A7F8 FFFFFC18 */  sd        $ra, -0x3e8($ra)
/* 4FA3DC 8021A7FC 00000000 */  nop       
/* 4FA3E0 8021A800 8021849C */  lb        $at, -0x7b64($at)
/* 4FA3E4 8021A804 8021A7F4 */  lb        $at, -0x580c($at)
/* 4FA3E8 8021A808 00000000 */  nop       
/* 4FA3EC 8021A80C 00000000 */  nop       
/* 4FA3F0 8021A810 00000000 */  nop       
/* 4FA3F4 8021A814 00000000 */  nop       
/* 4FA3F8 8021A818 00000000 */  nop       
/* 4FA3FC 8021A81C 00000000 */  nop       
/* 4FA400 8021A820 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA404 8021A824 004B0001 */  .byte     0x00, 0x4b, 0x00, 0x01
/* 4FA408 8021A828 0000000C */  syscall   
/* 4FA40C 8021A82C 004B0000 */  .byte     0x00, 0x4b, 0x00, 0x00
/* 4FA410 8021A830 00000006 */  srlv      $zero, $zero, $zero
/* 4FA414 8021A834 004B0009 */  .byte     0x00, 0x4b, 0x00, 0x09
/* 4FA418 8021A838 00000009 */  jr        $zero
/* 4FA41C 8021A83C 004B0001 */   .byte    0x00, 0x4b, 0x00, 0x01
/* 4FA420 8021A840 00000008 */  jr        $zero
/* 4FA424 8021A844 004B0000 */   .byte    0x00, 0x4b, 0x00, 0x00
/* 4FA428 8021A848 0000000B */  movn      $zero, $zero, $zero
/* 4FA42C 8021A84C 004B0001 */  .byte     0x00, 0x4b, 0x00, 0x01
/* 4FA430 8021A850 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA434 8021A854 004B0000 */  .byte     0x00, 0x4b, 0x00, 0x00
/* 4FA438 8021A858 00000004 */  sllv      $zero, $zero, $zero
/* 4FA43C 8021A85C 004B000A */  movz      $zero, $v0, $t3
/* 4FA440 8021A860 00000003 */  sra       $zero, $zero, 0
/* 4FA444 8021A864 004B000A */  movz      $zero, $v0, $t3
/* 4FA448 8021A868 00000000 */  nop       
/* 4FA44C 8021A86C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA450 8021A870 00000000 */  nop       
/* 4FA454 8021A874 00000000 */  nop       
/* 4FA458 8021A878 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA45C 8021A87C 00000000 */  nop       
/* 4FA460 8021A880 00000002 */  srl       $zero, $zero, 0
/* 4FA464 8021A884 00000000 */  nop       
/* 4FA468 8021A888 00000006 */  srlv      $zero, $zero, $zero
/* 4FA46C 8021A88C 0000003C */  dsll32    $zero, $zero, 0
/* 4FA470 8021A890 00000009 */  jr        $zero
/* 4FA474 8021A894 00000032 */   tlt      $zero, $zero
/* 4FA478 8021A898 00000007 */  srav      $zero, $zero, $zero
/* 4FA47C 8021A89C 00000000 */  nop       
/* 4FA480 8021A8A0 00000004 */  sllv      $zero, $zero, $zero
/* 4FA484 8021A8A4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FA488 8021A8A8 00000003 */  sra       $zero, $zero, 0
/* 4FA48C 8021A8AC 00000000 */  nop       
/* 4FA490 8021A8B0 0000000B */  movn      $zero, $zero, $zero
/* 4FA494 8021A8B4 00000000 */  nop       
/* 4FA498 8021A8B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA49C 8021A8BC 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4FA4A0 8021A8C0 0000000A */  movz      $zero, $zero, $zero
/* 4FA4A4 8021A8C4 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 4FA4A8 8021A8C8 00000008 */  jr        $zero
/* 4FA4AC 8021A8CC 0000005A */   .byte    0x00, 0x00, 0x00, 0x5a
/* 4FA4B0 8021A8D0 0000001F */  ddivu     $zero, $zero, $zero
/* 4FA4B4 8021A8D4 00000000 */  nop       
/* 4FA4B8 8021A8D8 00000020 */  add       $zero, $zero, $zero
/* 4FA4BC 8021A8DC 00000000 */  nop       
/* 4FA4C0 8021A8E0 00000025 */  or        $zero, $zero, $zero
/* 4FA4C4 8021A8E4 00000000 */  nop       
/* 4FA4C8 8021A8E8 00000022 */  neg       $zero, $zero
/* 4FA4CC 8021A8EC 00000000 */  nop       
/* 4FA4D0 8021A8F0 00000024 */  and       $zero, $zero, $zero
/* 4FA4D4 8021A8F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA4D8 8021A8F8 00000023 */  negu      $zero, $zero
/* 4FA4DC 8021A8FC 00000000 */  nop       
/* 4FA4E0 8021A900 00000021 */  addu      $zero, $zero, $zero
/* 4FA4E4 8021A904 00000000 */  nop       
/* 4FA4E8 8021A908 00000026 */  xor       $zero, $zero, $zero
/* 4FA4EC 8021A90C 00000000 */  nop       
/* 4FA4F0 8021A910 00000027 */  not       $zero, $zero
/* 4FA4F4 8021A914 00000000 */  nop       
/* 4FA4F8 8021A918 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4FA4FC 8021A91C 00000000 */  nop       
/* 4FA500 8021A920 00000000 */  nop       
/* 4FA504 8021A924 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 4FA508 8021A928 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 4FA50C 8021A92C F92100FF */  bbit132   $t1, 1, .L8021AD2C
/* 4FA510 8021A930 8021A820 */   lb       $at, -0x57e0($at)
/* 4FA514 8021A934 8021A86C */  lb        $at, -0x5794($at)
/* 4FA518 8021A938 00000000 */  nop       
/* 4FA51C 8021A93C 00000000 */  nop       
/* 4FA520 8021A940 02F60000 */  .byte     0x02, 0xf6, 0x00, 0x00
/* 4FA524 8021A944 00000000 */  nop       
/* 4FA528 8021A948 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4FA52C 8021A94C 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 4FA530 8021A950 001800FF */  dsra32    $zero, $t8, 3
/* 4FA534 8021A954 8021A820 */  lb        $at, -0x57e0($at)
/* 4FA538 8021A958 8021A86C */  lb        $at, -0x5794($at)
/* 4FA53C 8021A95C 00000000 */  nop       
/* 4FA540 8021A960 00000000 */  nop       
/* 4FA544 8021A964 FFFB0000 */  sd        $k1, ($ra)
/* 4FA548 8021A968 00000000 */  nop       
/* 4FA54C 8021A96C 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4FA550 8021A970 03000000 */  .byte     0x03, 0x00, 0x00, 0x00
/* 4FA554 8021A974 001800FF */  dsra32    $zero, $t8, 3
/* 4FA558 8021A978 8021A820 */  lb        $at, -0x57e0($at)
/* 4FA55C 8021A97C 8021A86C */  lb        $at, -0x5794($at)
/* 4FA560 8021A980 00000000 */  nop       
/* 4FA564 8021A984 00000000 */  nop       
/* 4FA568 8021A988 FFFB0000 */  sd        $k1, ($ra)
/* 4FA56C 8021A98C 00000000 */  nop       
/* 4FA570 8021A990 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4FA574 8021A994 04000000 */  bltz      $zero, .L8021A998
.L8021A998:
/* 4FA578 8021A998 001800FF */   dsra32   $zero, $t8, 3
/* 4FA57C 8021A99C 8021A820 */  lb        $at, -0x57e0($at)
/* 4FA580 8021A9A0 8021A86C */  lb        $at, -0x5794($at)
/* 4FA584 8021A9A4 00000000 */  nop       
/* 4FA588 8021A9A8 00000000 */  nop       
/* 4FA58C 8021A9AC FFFB0000 */  sd        $k1, ($ra)
/* 4FA590 8021A9B0 00000000 */  nop       
/* 4FA594 8021A9B4 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4FA598 8021A9B8 05000000 */  bltz      $t0, .L8021A9BC
.L8021A9BC:
/* 4FA59C 8021A9BC 001800FF */   dsra32   $zero, $t8, 3
/* 4FA5A0 8021A9C0 8021A820 */  lb        $at, -0x57e0($at)
/* 4FA5A4 8021A9C4 8021A86C */  lb        $at, -0x5794($at)
/* 4FA5A8 8021A9C8 00000000 */  nop       
/* 4FA5AC 8021A9CC 00000000 */  nop       
/* 4FA5B0 8021A9D0 FFFB0000 */  sd        $k1, ($ra)
/* 4FA5B4 8021A9D4 00000000 */  nop       
/* 4FA5B8 8021A9D8 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4FA5BC 8021A9DC 06000000 */  bltz      $s0, .L8021A9E0
.L8021A9E0:
/* 4FA5C0 8021A9E0 001800FF */   dsra32   $zero, $t8, 3
/* 4FA5C4 8021A9E4 8021A820 */  lb        $at, -0x57e0($at)
/* 4FA5C8 8021A9E8 8021A86C */  lb        $at, -0x5794($at)
/* 4FA5CC 8021A9EC 00000000 */  nop       
/* 4FA5D0 8021A9F0 00000000 */  nop       
/* 4FA5D4 8021A9F4 FFFB0000 */  sd        $k1, ($ra)
/* 4FA5D8 8021A9F8 00000000 */  nop       
/* 4FA5DC 8021A9FC 00000200 */  sll       $zero, $zero, 8
/* 4FA5E0 8021AA00 00311303 */  .byte     0x00, 0x31, 0x13, 0x03
/* 4FA5E4 8021AA04 00060000 */  sll       $zero, $a2, 0
/* 4FA5E8 8021AA08 8021A924 */  lb        $at, -0x56dc($at)
/* 4FA5EC 8021AA0C 8021AA24 */  lb        $at, -0x55dc($at)
/* 4FA5F0 8021AA10 8021A878 */  lb        $at, -0x5788($at)
/* 4FA5F4 8021AA14 285F5F46 */  slti      $ra, $v0, 0x5f46
/* 4FA5F8 8021AA18 5F005A01 */  bgtzl     $t8, .L80231220
/* 4FA5FC 8021AA1C 26260000 */   addiu    $a2, $s1, 0
/* 4FA600 8021AA20 F6140A14 */  sdc1      $f20, 0xa14($s0)
/* 4FA604 8021AA24 00000043 */  sra       $zero, $zero, 1
/* 4FA608 8021AA28 00000003 */  sra       $zero, $zero, 0
/* 4FA60C 8021AA2C 80278930 */  lb        $a3, -0x76d0($at)
/* 4FA610 8021AA30 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA614 8021AA34 8021D28C */  lb        $at, -0x2d74($at)
/* 4FA618 8021AA38 00000043 */  sra       $zero, $zero, 1
/* 4FA61C 8021AA3C 00000003 */  sra       $zero, $zero, 0
/* 4FA620 8021AA40 80278A94 */  lb        $a3, -0x756c($at)
/* 4FA624 8021AA44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA628 8021AA48 8021AB10 */  lb        $at, -0x54f0($at)
/* 4FA62C 8021AA4C 00000043 */  sra       $zero, $zero, 1
/* 4FA630 8021AA50 00000003 */  sra       $zero, $zero, 0
/* 4FA634 8021AA54 80278C20 */  lb        $a3, -0x73e0($at)
/* 4FA638 8021AA58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA63C 8021AA5C 8021ACA8 */  lb        $at, -0x5358($at)
/* 4FA640 8021AA60 00000043 */  sra       $zero, $zero, 1
/* 4FA644 8021AA64 00000006 */  srlv      $zero, $zero, $zero
/* 4FA648 8021AA68 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4FA64C 8021AA6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA650 8021AA70 00000002 */  srl       $zero, $zero, 0
/* 4FA654 8021AA74 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA658 8021AA78 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA65C 8021AA7C F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA660 8021AA80 00000043 */  sra       $zero, $zero, 1
/* 4FA664 8021AA84 00000006 */  srlv      $zero, $zero, $zero
/* 4FA668 8021AA88 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4FA66C 8021AA8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA670 8021AA90 00000003 */  sra       $zero, $zero, 0
/* 4FA674 8021AA94 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA678 8021AA98 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA67C 8021AA9C F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA680 8021AAA0 00000043 */  sra       $zero, $zero, 1
/* 4FA684 8021AAA4 00000006 */  srlv      $zero, $zero, $zero
/* 4FA688 8021AAA8 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4FA68C 8021AAAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA690 8021AAB0 00000004 */  sllv      $zero, $zero, $zero
/* 4FA694 8021AAB4 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA698 8021AAB8 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA69C 8021AABC F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6A0 8021AAC0 00000043 */  sra       $zero, $zero, 1
/* 4FA6A4 8021AAC4 00000006 */  srlv      $zero, $zero, $zero
/* 4FA6A8 8021AAC8 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4FA6AC 8021AACC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA6B0 8021AAD0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA6B4 8021AAD4 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6B8 8021AAD8 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6BC 8021AADC F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6C0 8021AAE0 00000043 */  sra       $zero, $zero, 1
/* 4FA6C4 8021AAE4 00000006 */  srlv      $zero, $zero, $zero
/* 4FA6C8 8021AAE8 8026CB4C */  lb        $a2, -0x34b4($at)
/* 4FA6CC 8021AAEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA6D0 8021AAF0 00000006 */  srlv      $zero, $zero, $zero
/* 4FA6D4 8021AAF4 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6D8 8021AAF8 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6DC 8021AAFC F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 4FA6E0 8021AB00 00000002 */  srl       $zero, $zero, 0
/* 4FA6E4 8021AB04 00000000 */  nop       
/* 4FA6E8 8021AB08 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA6EC 8021AB0C 00000000 */  nop       
/* 4FA6F0 8021AB10 00000003 */  sra       $zero, $zero, 0
/* 4FA6F4 8021AB14 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA6F8 8021AB18 00000000 */  nop       
/* 4FA6FC 8021AB1C 00000043 */  sra       $zero, $zero, 1
/* 4FA700 8021AB20 00000003 */  sra       $zero, $zero, 0
/* 4FA704 8021AB24 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FA708 8021AB28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA70C 8021AB2C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FA710 8021AB30 00000010 */  mfhi      $zero
/* 4FA714 8021AB34 00000002 */  srl       $zero, $zero, 0
/* 4FA718 8021AB38 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FA71C 8021AB3C 00041000 */  sll       $v0, $a0, 0
/* 4FA720 8021AB40 00000043 */  sra       $zero, $zero, 1
/* 4FA724 8021AB44 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA728 8021AB48 8027D380 */  lb        $a3, -0x2c80($at)
/* 4FA72C 8021AB4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA730 8021AB50 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA734 8021AB54 FFFFFFF9 */  sd        $ra, -7($ra)
/* 4FA738 8021AB58 00000013 */  mtlo      $zero
/* 4FA73C 8021AB5C 00000043 */  sra       $zero, $zero, 1
/* 4FA740 8021AB60 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA744 8021AB64 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4FA748 8021AB68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA74C 8021AB6C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA750 8021AB70 00000002 */  srl       $zero, $zero, 0
/* 4FA754 8021AB74 FFFFFFFA */  sd        $ra, -6($ra)
/* 4FA758 8021AB78 00000043 */  sra       $zero, $zero, 1
/* 4FA75C 8021AB7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA760 8021AB80 80218170 */  lb        $at, -0x7e90($at)
/* 4FA764 8021AB84 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 4FA768 8021AB88 00000014 */  dsllv     $zero, $zero, $zero
/* 4FA76C 8021AB8C 0000000A */  movz      $zero, $zero, $zero
/* 4FA770 8021AB90 0000001B */  divu      $zero, $zero, $zero
/* 4FA774 8021AB94 00000012 */  mflo      $zero
/* 4FA778 8021AB98 00000000 */  nop       
/* 4FA77C 8021AB9C 00000043 */  sra       $zero, $zero, 1
/* 4FA780 8021ABA0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA784 8021ABA4 8027D380 */  lb        $a3, -0x2c80($at)
/* 4FA788 8021ABA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA78C 8021ABAC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA790 8021ABB0 FFFFFFF9 */  sd        $ra, -7($ra)
/* 4FA794 8021ABB4 00000021 */  addu      $zero, $zero, $zero
/* 4FA798 8021ABB8 00000043 */  sra       $zero, $zero, 1
/* 4FA79C 8021ABBC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA7A0 8021ABC0 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 4FA7A4 8021ABC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA7A8 8021ABC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA7AC 8021ABCC 00000002 */  srl       $zero, $zero, 0
/* 4FA7B0 8021ABD0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FA7B4 8021ABD4 00000043 */  sra       $zero, $zero, 1
/* 4FA7B8 8021ABD8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA7BC 8021ABDC 80218170 */  lb        $at, -0x7e90($at)
/* 4FA7C0 8021ABE0 FFFFFFF0 */  sd        $ra, -0x10($ra)
/* 4FA7C4 8021ABE4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA7C8 8021ABE8 00000004 */  sllv      $zero, $zero, $zero
/* 4FA7CC 8021ABEC 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA7D0 8021ABF0 00000013 */  mtlo      $zero
/* 4FA7D4 8021ABF4 00000000 */  nop       
/* 4FA7D8 8021ABF8 00000008 */  jr        $zero
/* 4FA7DC 8021ABFC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FA7E0 8021AC00 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA7E4 8021AC04 00000004 */  sllv      $zero, $zero, $zero
/* 4FA7E8 8021AC08 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA7EC 8021AC0C 00000000 */  nop       
/* 4FA7F0 8021AC10 00000002 */  srl       $zero, $zero, 0
/* 4FA7F4 8021AC14 00000000 */  nop       
/* 4FA7F8 8021AC18 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA7FC 8021AC1C 00000000 */  nop       
/* 4FA800 8021AC20 00000043 */  sra       $zero, $zero, 1
/* 4FA804 8021AC24 00000006 */  srlv      $zero, $zero, $zero
/* 4FA808 8021AC28 8026C634 */  lb        $a2, -0x39cc($at)
/* 4FA80C 8021AC2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA810 8021AC30 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA814 8021AC34 00000000 */  nop       
/* 4FA818 8021AC38 00000000 */  nop       
/* 4FA81C 8021AC3C 00000000 */  nop       
/* 4FA820 8021AC40 00000043 */  sra       $zero, $zero, 1
/* 4FA824 8021AC44 00000004 */  sllv      $zero, $zero, $zero
/* 4FA828 8021AC48 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FA82C 8021AC4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA830 8021AC50 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA834 8021AC54 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FA838 8021AC58 00000043 */  sra       $zero, $zero, 1
/* 4FA83C 8021AC5C 00000002 */  srl       $zero, $zero, 0
/* 4FA840 8021AC60 80269EC4 */  lb        $a2, -0x613c($at)
/* 4FA844 8021AC64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA848 8021AC68 00000043 */  sra       $zero, $zero, 1
/* 4FA84C 8021AC6C 00000003 */  sra       $zero, $zero, 0
/* 4FA850 8021AC70 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FA854 8021AC74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA858 8021AC78 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4FA85C 8021AC7C 00000043 */  sra       $zero, $zero, 1
/* 4FA860 8021AC80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FA864 8021AC84 8027B624 */  lb        $a3, -0x49dc($at)
/* 4FA868 8021AC88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA86C 8021AC8C 00000000 */  nop       
/* 4FA870 8021AC90 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA874 8021AC94 0000000B */  movn      $zero, $zero, $zero
/* 4FA878 8021AC98 00000002 */  srl       $zero, $zero, 0
/* 4FA87C 8021AC9C 00000000 */  nop       
/* 4FA880 8021ACA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA884 8021ACA4 00000000 */  nop       
/* 4FA888 8021ACA8 00000043 */  sra       $zero, $zero, 1
/* 4FA88C 8021ACAC 00000003 */  sra       $zero, $zero, 0
/* 4FA890 8021ACB0 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FA894 8021ACB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA898 8021ACB8 00000000 */  nop       
/* 4FA89C 8021ACBC 00000043 */  sra       $zero, $zero, 1
/* 4FA8A0 8021ACC0 00000003 */  sra       $zero, $zero, 0
/* 4FA8A4 8021ACC4 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FA8A8 8021ACC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA8AC 8021ACCC 00000000 */  nop       
/* 4FA8B0 8021ACD0 00000043 */  sra       $zero, $zero, 1
/* 4FA8B4 8021ACD4 00000003 */  sra       $zero, $zero, 0
/* 4FA8B8 8021ACD8 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 4FA8BC 8021ACDC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FA8C0 8021ACE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA8C4 8021ACE4 00000014 */  dsllv     $zero, $zero, $zero
/* 4FA8C8 8021ACE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA8CC 8021ACEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA8D0 8021ACF0 0000001D */  dmultu    $zero, $zero
/* 4FA8D4 8021ACF4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA8D8 8021ACF8 00000009 */  jr        $zero
/* 4FA8DC 8021ACFC 0000001D */   dmultu   $zero, $zero
/* 4FA8E0 8021AD00 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA8E4 8021AD04 0000000A */  movz      $zero, $zero, $zero
/* 4FA8E8 8021AD08 00000025 */  or        $zero, $zero, $zero
/* 4FA8EC 8021AD0C 00000002 */  srl       $zero, $zero, 0
/* 4FA8F0 8021AD10 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA8F4 8021AD14 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA8F8 8021AD18 00000025 */  or        $zero, $zero, $zero
/* 4FA8FC 8021AD1C 00000002 */  srl       $zero, $zero, 0
/* 4FA900 8021AD20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FA904 8021AD24 004B0006 */  srlv      $zero, $t3, $v0
/* 4FA908 8021AD28 00000046 */  rotrv     $zero, $zero, $zero
.L8021AD2C:
/* 4FA90C 8021AD2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA910 8021AD30 80299044 */  lb        $t1, -0x6fbc($at)
/* 4FA914 8021AD34 00000020 */  add       $zero, $zero, $zero
/* 4FA918 8021AD38 00000000 */  nop       
/* 4FA91C 8021AD3C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA920 8021AD40 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA924 8021AD44 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4FA928 8021AD48 00000025 */  or        $zero, $zero, $zero
/* 4FA92C 8021AD4C 00000002 */  srl       $zero, $zero, 0
/* 4FA930 8021AD50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA934 8021AD54 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA938 8021AD58 00000025 */  or        $zero, $zero, $zero
/* 4FA93C 8021AD5C 00000002 */  srl       $zero, $zero, 0
/* 4FA940 8021AD60 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FA944 8021AD64 004B0007 */  srav      $zero, $t3, $v0
/* 4FA948 8021AD68 00000025 */  or        $zero, $zero, $zero
/* 4FA94C 8021AD6C 00000002 */  srl       $zero, $zero, 0
/* 4FA950 8021AD70 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FA954 8021AD74 004B0008 */  .byte     0x00, 0x4b, 0x00, 0x08
/* 4FA958 8021AD78 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA95C 8021AD7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA960 8021AD80 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4FA964 8021AD84 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA968 8021AD88 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA96C 8021AD8C 00000024 */  and       $zero, $zero, $zero
/* 4FA970 8021AD90 00000025 */  or        $zero, $zero, $zero
/* 4FA974 8021AD94 00000002 */  srl       $zero, $zero, 0
/* 4FA978 8021AD98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA97C 8021AD9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA980 8021ADA0 00000025 */  or        $zero, $zero, $zero
/* 4FA984 8021ADA4 00000002 */  srl       $zero, $zero, 0
/* 4FA988 8021ADA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FA98C 8021ADAC 004B0007 */  srav      $zero, $t3, $v0
/* 4FA990 8021ADB0 00000025 */  or        $zero, $zero, $zero
/* 4FA994 8021ADB4 00000002 */  srl       $zero, $zero, 0
/* 4FA998 8021ADB8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FA99C 8021ADBC 004B0008 */  .byte     0x00, 0x4b, 0x00, 0x08
/* 4FA9A0 8021ADC0 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA9A4 8021ADC4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA9A8 8021ADC8 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4FA9AC 8021ADCC 00000025 */  or        $zero, $zero, $zero
/* 4FA9B0 8021ADD0 00000002 */  srl       $zero, $zero, 0
/* 4FA9B4 8021ADD4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA9B8 8021ADD8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA9BC 8021ADDC 00000025 */  or        $zero, $zero, $zero
/* 4FA9C0 8021ADE0 00000002 */  srl       $zero, $zero, 0
/* 4FA9C4 8021ADE4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FA9C8 8021ADE8 004B0008 */  .byte     0x00, 0x4b, 0x00, 0x08
/* 4FA9CC 8021ADEC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FA9D0 8021ADF0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA9D4 8021ADF4 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FA9D8 8021ADF8 00000002 */  srl       $zero, $zero, 0
/* 4FA9DC 8021ADFC 00000000 */  nop       
/* 4FA9E0 8021AE00 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FA9E4 8021AE04 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA9E8 8021AE08 0000000B */  movn      $zero, $zero, $zero
/* 4FA9EC 8021AE0C 00000025 */  or        $zero, $zero, $zero
/* 4FA9F0 8021AE10 00000002 */  srl       $zero, $zero, 0
/* 4FA9F4 8021AE14 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FA9F8 8021AE18 00000001 */  movf      $zero, $zero, $fcc0
/* 4FA9FC 8021AE1C 00000025 */  or        $zero, $zero, $zero
/* 4FAA00 8021AE20 00000002 */  srl       $zero, $zero, 0
/* 4FAA04 8021AE24 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAA08 8021AE28 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAA0C 8021AE2C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAA10 8021AE30 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA14 8021AE34 8029B998 */  lb        $t1, -0x4668($at)
/* 4FAA18 8021AE38 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAA1C 8021AE3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA20 8021AE40 00000021 */  addu      $zero, $zero, $zero
/* 4FAA24 8021AE44 00000025 */  or        $zero, $zero, $zero
/* 4FAA28 8021AE48 00000002 */  srl       $zero, $zero, 0
/* 4FAA2C 8021AE4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAA30 8021AE50 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA34 8021AE54 00000025 */  or        $zero, $zero, $zero
/* 4FAA38 8021AE58 00000002 */  srl       $zero, $zero, 0
/* 4FAA3C 8021AE5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAA40 8021AE60 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAA44 8021AE64 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAA48 8021AE68 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA4C 8021AE6C 8029B998 */  lb        $t1, -0x4668($at)
/* 4FAA50 8021AE70 00000025 */  or        $zero, $zero, $zero
/* 4FAA54 8021AE74 00000002 */  srl       $zero, $zero, 0
/* 4FAA58 8021AE78 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAA5C 8021AE7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA60 8021AE80 00000025 */  or        $zero, $zero, $zero
/* 4FAA64 8021AE84 00000002 */  srl       $zero, $zero, 0
/* 4FAA68 8021AE88 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAA6C 8021AE8C 004B000B */  movn      $zero, $v0, $t3
/* 4FAA70 8021AE90 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAA74 8021AE94 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA78 8021AE98 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FAA7C 8021AE9C 00000002 */  srl       $zero, $zero, 0
/* 4FAA80 8021AEA0 00000000 */  nop       
/* 4FAA84 8021AEA4 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAA88 8021AEA8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAA8C 8021AEAC 0000002F */  dsubu     $zero, $zero, $zero
/* 4FAA90 8021AEB0 00000025 */  or        $zero, $zero, $zero
/* 4FAA94 8021AEB4 00000002 */  srl       $zero, $zero, 0
/* 4FAA98 8021AEB8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAA9C 8021AEBC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAAA0 8021AEC0 00000025 */  or        $zero, $zero, $zero
/* 4FAAA4 8021AEC4 00000002 */  srl       $zero, $zero, 0
/* 4FAAA8 8021AEC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAAAC 8021AECC 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAAB0 8021AED0 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAAB4 8021AED4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAAB8 8021AED8 8029A6FC */  lb        $t1, -0x5904($at)
/* 4FAABC 8021AEDC 00000025 */  or        $zero, $zero, $zero
/* 4FAAC0 8021AEE0 00000002 */  srl       $zero, $zero, 0
/* 4FAAC4 8021AEE4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAAC8 8021AEE8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAACC 8021AEEC 00000025 */  or        $zero, $zero, $zero
/* 4FAAD0 8021AEF0 00000002 */  srl       $zero, $zero, 0
/* 4FAAD4 8021AEF4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAAD8 8021AEF8 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAADC 8021AEFC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAAE0 8021AF00 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAAE4 8021AF04 8029BD70 */  lb        $t1, -0x4290($at)
/* 4FAAE8 8021AF08 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAAEC 8021AF0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAAF0 8021AF10 8021AC20 */  lb        $at, -0x53e0($at)
/* 4FAAF4 8021AF14 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAAF8 8021AF18 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAAFC 8021AF1C 00000026 */  xor       $zero, $zero, $zero
/* 4FAB00 8021AF20 00000025 */  or        $zero, $zero, $zero
/* 4FAB04 8021AF24 00000002 */  srl       $zero, $zero, 0
/* 4FAB08 8021AF28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAB0C 8021AF2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB10 8021AF30 00000025 */  or        $zero, $zero, $zero
/* 4FAB14 8021AF34 00000002 */  srl       $zero, $zero, 0
/* 4FAB18 8021AF38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAB1C 8021AF3C 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAB20 8021AF40 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAB24 8021AF44 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB28 8021AF48 8029A6FC */  lb        $t1, -0x5904($at)
/* 4FAB2C 8021AF4C 00000025 */  or        $zero, $zero, $zero
/* 4FAB30 8021AF50 00000002 */  srl       $zero, $zero, 0
/* 4FAB34 8021AF54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAB38 8021AF58 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB3C 8021AF5C 00000025 */  or        $zero, $zero, $zero
/* 4FAB40 8021AF60 00000002 */  srl       $zero, $zero, 0
/* 4FAB44 8021AF64 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAB48 8021AF68 004B000B */  movn      $zero, $v0, $t3
/* 4FAB4C 8021AF6C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAB50 8021AF70 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB54 8021AF74 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FAB58 8021AF78 00000002 */  srl       $zero, $zero, 0
/* 4FAB5C 8021AF7C 00000000 */  nop       
/* 4FAB60 8021AF80 0000001D */  dmultu    $zero, $zero
/* 4FAB64 8021AF84 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB68 8021AF88 00000017 */  dsrav     $zero, $zero, $zero
/* 4FAB6C 8021AF8C 0000001D */  dmultu    $zero, $zero
/* 4FAB70 8021AF90 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB74 8021AF94 00000019 */  multu     $zero, $zero
/* 4FAB78 8021AF98 0000001D */  dmultu    $zero, $zero
/* 4FAB7C 8021AF9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB80 8021AFA0 0000001F */  ddivu     $zero, $zero, $zero
/* 4FAB84 8021AFA4 00000025 */  or        $zero, $zero, $zero
/* 4FAB88 8021AFA8 00000002 */  srl       $zero, $zero, 0
/* 4FAB8C 8021AFAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAB90 8021AFB0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAB94 8021AFB4 00000025 */  or        $zero, $zero, $zero
/* 4FAB98 8021AFB8 00000002 */  srl       $zero, $zero, 0
/* 4FAB9C 8021AFBC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FABA0 8021AFC0 004B0001 */  .byte     0x00, 0x4b, 0x00, 0x01
/* 4FABA4 8021AFC4 00000046 */  rotrv     $zero, $zero, $zero
/* 4FABA8 8021AFC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FABAC 8021AFCC 8029AC70 */  lb        $t1, -0x5390($at)
/* 4FABB0 8021AFD0 00000020 */  add       $zero, $zero, $zero
/* 4FABB4 8021AFD4 00000000 */  nop       
/* 4FABB8 8021AFD8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FABBC 8021AFDC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FABC0 8021AFE0 00000020 */  add       $zero, $zero, $zero
/* 4FABC4 8021AFE4 00000025 */  or        $zero, $zero, $zero
/* 4FABC8 8021AFE8 00000002 */  srl       $zero, $zero, 0
/* 4FABCC 8021AFEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FABD0 8021AFF0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FABD4 8021AFF4 00000025 */  or        $zero, $zero, $zero
/* 4FABD8 8021AFF8 00000002 */  srl       $zero, $zero, 0
/* 4FABDC 8021AFFC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FABE0 8021B000 004B0006 */  srlv      $zero, $t3, $v0
/* 4FABE4 8021B004 00000046 */  rotrv     $zero, $zero, $zero
/* 4FABE8 8021B008 00000001 */  movf      $zero, $zero, $fcc0
/* 4FABEC 8021B00C 80299044 */  lb        $t1, -0x6fbc($at)
/* 4FABF0 8021B010 00000008 */  jr        $zero
/* 4FABF4 8021B014 00000001 */   movf     $zero, $zero, $fcc0
/* 4FABF8 8021B018 0000000A */  movz      $zero, $zero, $zero
/* 4FABFC 8021B01C 00000025 */  or        $zero, $zero, $zero
/* 4FAC00 8021B020 00000002 */  srl       $zero, $zero, 0
/* 4FAC04 8021B024 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAC08 8021B028 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAC0C 8021B02C 00000025 */  or        $zero, $zero, $zero
/* 4FAC10 8021B030 00000002 */  srl       $zero, $zero, 0
/* 4FAC14 8021B034 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAC18 8021B038 004B000B */  movn      $zero, $v0, $t3
/* 4FAC1C 8021B03C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAC20 8021B040 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAC24 8021B044 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FAC28 8021B048 00000002 */  srl       $zero, $zero, 0
/* 4FAC2C 8021B04C 00000000 */  nop       
/* 4FAC30 8021B050 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAC34 8021B054 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAC38 8021B058 00000038 */  dsll      $zero, $zero, 0
/* 4FAC3C 8021B05C 00000043 */  sra       $zero, $zero, 1
/* 4FAC40 8021B060 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FAC44 8021B064 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4FAC48 8021B068 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAC4C 8021B06C 00000014 */  dsllv     $zero, $zero, $zero
/* 4FAC50 8021B070 00000000 */  nop       
/* 4FAC54 8021B074 00000000 */  nop       
/* 4FAC58 8021B078 00000043 */  sra       $zero, $zero, 1
/* 4FAC5C 8021B07C 00000002 */  srl       $zero, $zero, 0
/* 4FAC60 8021B080 8026D7A8 */  lb        $a2, -0x2858($at)
/* 4FAC64 8021B084 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAC68 8021B088 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAC6C 8021B08C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAC70 8021B090 00000035 */  .byte     0x00, 0x00, 0x00, 0x35
/* 4FAC74 8021B094 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAC78 8021B098 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAC7C 8021B09C 8021AC20 */  lb        $at, -0x53e0($at)
/* 4FAC80 8021B0A0 00000043 */  sra       $zero, $zero, 1
/* 4FAC84 8021B0A4 00000002 */  srl       $zero, $zero, 0
/* 4FAC88 8021B0A8 8026D664 */  lb        $a2, -0x299c($at)
/* 4FAC8C 8021B0AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAC90 8021B0B0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAC94 8021B0B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAC98 8021B0B8 00000031 */  tgeu      $zero, $zero
/* 4FAC9C 8021B0BC 00000025 */  or        $zero, $zero, $zero
/* 4FACA0 8021B0C0 00000002 */  srl       $zero, $zero, 0
/* 4FACA4 8021B0C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FACA8 8021B0C8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FACAC 8021B0CC 00000025 */  or        $zero, $zero, $zero
/* 4FACB0 8021B0D0 00000002 */  srl       $zero, $zero, 0
/* 4FACB4 8021B0D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FACB8 8021B0D8 004B0001 */  .byte     0x00, 0x4b, 0x00, 0x01
/* 4FACBC 8021B0DC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FACC0 8021B0E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FACC4 8021B0E4 8029BFA0 */  lb        $t1, -0x4060($at)
/* 4FACC8 8021B0E8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FACCC 8021B0EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FACD0 8021B0F0 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 4FACD4 8021B0F4 00000043 */  sra       $zero, $zero, 1
/* 4FACD8 8021B0F8 00000004 */  sllv      $zero, $zero, $zero
/* 4FACDC 8021B0FC 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FACE0 8021B100 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FACE4 8021B104 00000200 */  sll       $zero, $zero, 8
/* 4FACE8 8021B108 00000000 */  nop       
/* 4FACEC 8021B10C 00000025 */  or        $zero, $zero, $zero
/* 4FACF0 8021B110 00000002 */  srl       $zero, $zero, 0
/* 4FACF4 8021B114 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FACF8 8021B118 00000001 */  movf      $zero, $zero, $fcc0
/* 4FACFC 8021B11C 00000025 */  or        $zero, $zero, $zero
/* 4FAD00 8021B120 00000002 */  srl       $zero, $zero, 0
/* 4FAD04 8021B124 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAD08 8021B128 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FAD0C 8021B12C 00000025 */  or        $zero, $zero, $zero
/* 4FAD10 8021B130 00000002 */  srl       $zero, $zero, 0
/* 4FAD14 8021B134 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FAD18 8021B138 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAD1C 8021B13C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAD20 8021B140 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAD24 8021B144 8029B22C */  lb        $t1, -0x4dd4($at)
/* 4FAD28 8021B148 00000002 */  srl       $zero, $zero, 0
/* 4FAD2C 8021B14C 00000000 */  nop       
/* 4FAD30 8021B150 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAD34 8021B154 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAD38 8021B158 0000003A */  dsrl      $zero, $zero, 0
/* 4FAD3C 8021B15C 00000025 */  or        $zero, $zero, $zero
/* 4FAD40 8021B160 00000002 */  srl       $zero, $zero, 0
/* 4FAD44 8021B164 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAD48 8021B168 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAD4C 8021B16C 00000025 */  or        $zero, $zero, $zero
/* 4FAD50 8021B170 00000002 */  srl       $zero, $zero, 0
/* 4FAD54 8021B174 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAD58 8021B178 004B0001 */  .byte     0x00, 0x4b, 0x00, 0x01
/* 4FAD5C 8021B17C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAD60 8021B180 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAD64 8021B184 8029C37C */  lb        $t1, -0x3c84($at)
/* 4FAD68 8021B188 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAD6C 8021B18C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAD70 8021B190 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FAD74 8021B194 00000043 */  sra       $zero, $zero, 1
/* 4FAD78 8021B198 00000003 */  sra       $zero, $zero, 0
/* 4FAD7C 8021B19C 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FAD80 8021B1A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAD84 8021B1A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAD88 8021B1A8 00000011 */  mthi      $zero
/* 4FAD8C 8021B1AC 00000002 */  srl       $zero, $zero, 0
/* 4FAD90 8021B1B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAD94 8021B1B4 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 4FAD98 8021B1B8 00000010 */  mfhi      $zero
/* 4FAD9C 8021B1BC 00000002 */  srl       $zero, $zero, 0
/* 4FADA0 8021B1C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FADA4 8021B1C4 00080000 */  sll       $zero, $t0, 0
/* 4FADA8 8021B1C8 00000043 */  sra       $zero, $zero, 1
/* 4FADAC 8021B1CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FADB0 8021B1D0 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4FADB4 8021B1D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FADB8 8021B1D8 00000000 */  nop       
/* 4FADBC 8021B1DC 00000003 */  sra       $zero, $zero, 0
/* 4FADC0 8021B1E0 00000000 */  nop       
/* 4FADC4 8021B1E4 00000012 */  mflo      $zero
/* 4FADC8 8021B1E8 00000000 */  nop       
/* 4FADCC 8021B1EC 00000043 */  sra       $zero, $zero, 1
/* 4FADD0 8021B1F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FADD4 8021B1F4 8026BA04 */  lb        $a2, -0x45fc($at)
/* 4FADD8 8021B1F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FADDC 8021B1FC 00000000 */  nop       
/* 4FADE0 8021B200 00000009 */  jr        $zero
/* 4FADE4 8021B204 00000000 */   nop      
/* 4FADE8 8021B208 00000013 */  mtlo      $zero
/* 4FADEC 8021B20C 00000000 */  nop       
/* 4FADF0 8021B210 00000013 */  mtlo      $zero
/* 4FADF4 8021B214 00000000 */  nop       
/* 4FADF8 8021B218 00000025 */  or        $zero, $zero, $zero
/* 4FADFC 8021B21C 00000002 */  srl       $zero, $zero, 0
/* 4FAE00 8021B220 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAE04 8021B224 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAE08 8021B228 00000025 */  or        $zero, $zero, $zero
/* 4FAE0C 8021B22C 00000002 */  srl       $zero, $zero, 0
/* 4FAE10 8021B230 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAE14 8021B234 004B0006 */  srlv      $zero, $t3, $v0
/* 4FAE18 8021B238 00000046 */  rotrv     $zero, $zero, $zero
/* 4FAE1C 8021B23C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAE20 8021B240 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 4FAE24 8021B244 0000001C */  dmult     $zero, $zero
/* 4FAE28 8021B248 00000000 */  nop       
/* 4FAE2C 8021B24C 00000023 */  negu      $zero, $zero
/* 4FAE30 8021B250 00000000 */  nop       
/* 4FAE34 8021B254 00000043 */  sra       $zero, $zero, 1
/* 4FAE38 8021B258 00000003 */  sra       $zero, $zero, 0
/* 4FAE3C 8021B25C 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FAE40 8021B260 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAE44 8021B264 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAE48 8021B268 00000043 */  sra       $zero, $zero, 1
/* 4FAE4C 8021B26C 00000003 */  sra       $zero, $zero, 0
/* 4FAE50 8021B270 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FAE54 8021B274 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAE58 8021B278 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAE5C 8021B27C 00000002 */  srl       $zero, $zero, 0
/* 4FAE60 8021B280 00000000 */  nop       
/* 4FAE64 8021B284 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAE68 8021B288 00000000 */  nop       
/* 4FAE6C 8021B28C 00000043 */  sra       $zero, $zero, 1
/* 4FAE70 8021B290 00000003 */  sra       $zero, $zero, 0
/* 4FAE74 8021B294 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FAE78 8021B298 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAE7C 8021B29C 00000000 */  nop       
/* 4FAE80 8021B2A0 00000043 */  sra       $zero, $zero, 1
/* 4FAE84 8021B2A4 00000003 */  sra       $zero, $zero, 0
/* 4FAE88 8021B2A8 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FAE8C 8021B2AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAE90 8021B2B0 00000000 */  nop       
/* 4FAE94 8021B2B4 00000043 */  sra       $zero, $zero, 1
/* 4FAE98 8021B2B8 00000003 */  sra       $zero, $zero, 0
/* 4FAE9C 8021B2BC 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4FAEA0 8021B2C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAEA4 8021B2C4 00000000 */  nop       
/* 4FAEA8 8021B2C8 00000043 */  sra       $zero, $zero, 1
/* 4FAEAC 8021B2CC 00000002 */  srl       $zero, $zero, 0
/* 4FAEB0 8021B2D0 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FAEB4 8021B2D4 0000003F */  dsra32    $zero, $zero, 0
/* 4FAEB8 8021B2D8 00000043 */  sra       $zero, $zero, 1
/* 4FAEBC 8021B2DC 00000002 */  srl       $zero, $zero, 0
/* 4FAEC0 8021B2E0 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4FAEC4 8021B2E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAEC8 8021B2E8 00000043 */  sra       $zero, $zero, 1
/* 4FAECC 8021B2EC 00000004 */  sllv      $zero, $zero, $zero
/* 4FAED0 8021B2F0 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4FAED4 8021B2F4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4FAED8 8021B2F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAEDC 8021B2FC 00000000 */  nop       
/* 4FAEE0 8021B300 00000043 */  sra       $zero, $zero, 1
/* 4FAEE4 8021B304 00000004 */  sllv      $zero, $zero, $zero
/* 4FAEE8 8021B308 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FAEEC 8021B30C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAEF0 8021B310 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAEF4 8021B314 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FAEF8 8021B318 00000043 */  sra       $zero, $zero, 1
/* 4FAEFC 8021B31C 00000002 */  srl       $zero, $zero, 0
/* 4FAF00 8021B320 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FAF04 8021B324 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAF08 8021B328 00000043 */  sra       $zero, $zero, 1
/* 4FAF0C 8021B32C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FAF10 8021B330 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FAF14 8021B334 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAF18 8021B338 00000034 */  teq       $zero, $zero
/* 4FAF1C 8021B33C 0000000A */  movz      $zero, $zero, $zero
/* 4FAF20 8021B340 00000000 */  nop       
/* 4FAF24 8021B344 00000043 */  sra       $zero, $zero, 1
/* 4FAF28 8021B348 00000003 */  sra       $zero, $zero, 0
/* 4FAF2C 8021B34C 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FAF30 8021B350 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAF34 8021B354 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4FAF38 8021B358 00000043 */  sra       $zero, $zero, 1
/* 4FAF3C 8021B35C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FAF40 8021B360 8027B624 */  lb        $a3, -0x49dc($at)
/* 4FAF44 8021B364 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAF48 8021B368 00000000 */  nop       
/* 4FAF4C 8021B36C FFFFFFFC */  sd        $ra, -4($ra)
/* 4FAF50 8021B370 0000000C */  syscall   
/* 4FAF54 8021B374 00000043 */  sra       $zero, $zero, 1
/* 4FAF58 8021B378 00000007 */  srav      $zero, $zero, $zero
/* 4FAF5C 8021B37C 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4FAF60 8021B380 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAF64 8021B384 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAF68 8021B388 00000000 */  nop       
/* 4FAF6C 8021B38C 00000000 */  nop       
/* 4FAF70 8021B390 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAF74 8021B394 00000010 */  mfhi      $zero
/* 4FAF78 8021B398 00000014 */  dsllv     $zero, $zero, $zero
/* 4FAF7C 8021B39C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAF80 8021B3A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAF84 8021B3A4 0000001D */  dmultu    $zero, $zero
/* 4FAF88 8021B3A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAF8C 8021B3AC 00000006 */  srlv      $zero, $zero, $zero
/* 4FAF90 8021B3B0 0000001D */  dmultu    $zero, $zero
/* 4FAF94 8021B3B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FAF98 8021B3B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FAF9C 8021B3BC 00000024 */  and       $zero, $zero, $zero
/* 4FAFA0 8021B3C0 00000002 */  srl       $zero, $zero, 0
/* 4FAFA4 8021B3C4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FAFA8 8021B3C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAFAC 8021B3CC 00000008 */  jr        $zero
/* 4FAFB0 8021B3D0 00000001 */   movf     $zero, $zero, $fcc0
/* 4FAFB4 8021B3D4 0000000A */  movz      $zero, $zero, $zero
/* 4FAFB8 8021B3D8 00000043 */  sra       $zero, $zero, 1
/* 4FAFBC 8021B3DC 00000002 */  srl       $zero, $zero, 0
/* 4FAFC0 8021B3E0 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FAFC4 8021B3E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAFC8 8021B3E8 00000043 */  sra       $zero, $zero, 1
/* 4FAFCC 8021B3EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FAFD0 8021B3F0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FAFD4 8021B3F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FAFD8 8021B3F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAFDC 8021B3FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FAFE0 8021B400 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FAFE4 8021B404 00000027 */  not       $zero, $zero
/* 4FAFE8 8021B408 00000002 */  srl       $zero, $zero, 0
/* 4FAFEC 8021B40C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FAFF0 8021B410 00000014 */  dsllv     $zero, $zero, $zero
/* 4FAFF4 8021B414 00000027 */  not       $zero, $zero
/* 4FAFF8 8021B418 00000002 */  srl       $zero, $zero, 0
/* 4FAFFC 8021B41C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FB000 8021B420 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB004 8021B424 00000043 */  sra       $zero, $zero, 1
/* 4FB008 8021B428 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB00C 8021B42C 8026A510 */  lb        $a2, -0x5af0($at)
/* 4FB010 8021B430 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB014 8021B434 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB018 8021B438 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FB01C 8021B43C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FB020 8021B440 00000043 */  sra       $zero, $zero, 1
/* 4FB024 8021B444 00000003 */  sra       $zero, $zero, 0
/* 4FB028 8021B448 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FB02C 8021B44C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB030 8021B450 F24A9A80 */  scd       $t2, -0x6580($s2)
/* 4FB034 8021B454 00000043 */  sra       $zero, $zero, 1
/* 4FB038 8021B458 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB03C 8021B45C 8027B624 */  lb        $a3, -0x49dc($at)
/* 4FB040 8021B460 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB044 8021B464 00000000 */  nop       
/* 4FB048 8021B468 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FB04C 8021B46C 00000004 */  sllv      $zero, $zero, $zero
/* 4FB050 8021B470 00000008 */  jr        $zero
/* 4FB054 8021B474 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB058 8021B478 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB05C 8021B47C 00000043 */  sra       $zero, $zero, 1
/* 4FB060 8021B480 00000003 */  sra       $zero, $zero, 0
/* 4FB064 8021B484 8025385C */  lb        $a1, 0x385c($at)
/* 4FB068 8021B488 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB06C 8021B48C 000020CA */  .byte     0x00, 0x00, 0x20, 0xca
/* 4FB070 8021B490 00000043 */  sra       $zero, $zero, 1
/* 4FB074 8021B494 00000004 */  sllv      $zero, $zero, $zero
/* 4FB078 8021B498 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FB07C 8021B49C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB080 8021B4A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB084 8021B4A4 004B0004 */  sllv      $zero, $t3, $v0
/* 4FB088 8021B4A8 00000008 */  jr        $zero
/* 4FB08C 8021B4AC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB090 8021B4B0 0000000A */  movz      $zero, $zero, $zero
/* 4FB094 8021B4B4 0000000A */  movz      $zero, $zero, $zero
/* 4FB098 8021B4B8 00000002 */  srl       $zero, $zero, 0
/* 4FB09C 8021B4BC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB0A0 8021B4C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB0A4 8021B4C4 00000043 */  sra       $zero, $zero, 1
/* 4FB0A8 8021B4C8 00000007 */  srav      $zero, $zero, $zero
/* 4FB0AC 8021B4CC 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4FB0B0 8021B4D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB0B4 8021B4D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB0B8 8021B4D8 80000000 */  lb        $zero, ($zero)
/* 4FB0BC 8021B4DC 00000000 */  nop       
/* 4FB0C0 8021B4E0 00000000 */  nop       
/* 4FB0C4 8021B4E4 00000000 */  nop       
/* 4FB0C8 8021B4E8 00000013 */  mtlo      $zero
/* 4FB0CC 8021B4EC 00000000 */  nop       
/* 4FB0D0 8021B4F0 00000008 */  jr        $zero
/* 4FB0D4 8021B4F4 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB0D8 8021B4F8 0000000F */  sync      
/* 4FB0DC 8021B4FC 00000043 */  sra       $zero, $zero, 1
/* 4FB0E0 8021B500 00000002 */  srl       $zero, $zero, 0
/* 4FB0E4 8021B504 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FB0E8 8021B508 00000002 */  srl       $zero, $zero, 0
/* 4FB0EC 8021B50C 00000043 */  sra       $zero, $zero, 1
/* 4FB0F0 8021B510 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB0F4 8021B514 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4FB0F8 8021B518 00000043 */  sra       $zero, $zero, 1
/* 4FB0FC 8021B51C 00000003 */  sra       $zero, $zero, 0
/* 4FB100 8021B520 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4FB104 8021B524 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB108 8021B528 000000B4 */  teq       $zero, $zero, 2
/* 4FB10C 8021B52C 00000043 */  sra       $zero, $zero, 1
/* 4FB110 8021B530 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB114 8021B534 8026EE88 */  lb        $a2, -0x1178($at)
/* 4FB118 8021B538 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB11C 8021B53C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB120 8021B540 00000000 */  nop       
/* 4FB124 8021B544 00000002 */  srl       $zero, $zero, 0
/* 4FB128 8021B548 00000046 */  rotrv     $zero, $zero, $zero
/* 4FB12C 8021B54C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB130 8021B550 8021AC20 */  lb        $at, -0x53e0($at)
/* 4FB134 8021B554 00000043 */  sra       $zero, $zero, 1
/* 4FB138 8021B558 00000004 */  sllv      $zero, $zero, $zero
/* 4FB13C 8021B55C 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4FB140 8021B560 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB144 8021B564 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB148 8021B568 00000000 */  nop       
/* 4FB14C 8021B56C 00000043 */  sra       $zero, $zero, 1
/* 4FB150 8021B570 00000003 */  sra       $zero, $zero, 0
/* 4FB154 8021B574 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4FB158 8021B578 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB15C 8021B57C 00000000 */  nop       
/* 4FB160 8021B580 00000043 */  sra       $zero, $zero, 1
/* 4FB164 8021B584 00000003 */  sra       $zero, $zero, 0
/* 4FB168 8021B588 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FB16C 8021B58C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB170 8021B590 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB174 8021B594 00000043 */  sra       $zero, $zero, 1
/* 4FB178 8021B598 00000003 */  sra       $zero, $zero, 0
/* 4FB17C 8021B59C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FB180 8021B5A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB184 8021B5A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB188 8021B5A8 00000002 */  srl       $zero, $zero, 0
/* 4FB18C 8021B5AC 00000000 */  nop       
/* 4FB190 8021B5B0 00000020 */  add       $zero, $zero, $zero
/* 4FB194 8021B5B4 00000000 */  nop       
/* 4FB198 8021B5B8 00000023 */  negu      $zero, $zero
/* 4FB19C 8021B5BC 00000000 */  nop       
/* 4FB1A0 8021B5C0 00000008 */  jr        $zero
/* 4FB1A4 8021B5C4 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB1A8 8021B5C8 0000000A */  movz      $zero, $zero, $zero
/* 4FB1AC 8021B5CC 00000043 */  sra       $zero, $zero, 1
/* 4FB1B0 8021B5D0 00000002 */  srl       $zero, $zero, 0
/* 4FB1B4 8021B5D4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FB1B8 8021B5D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB1BC 8021B5DC 00000043 */  sra       $zero, $zero, 1
/* 4FB1C0 8021B5E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB1C4 8021B5E4 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FB1C8 8021B5E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB1CC 8021B5EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB1D0 8021B5F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FB1D4 8021B5F4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FB1D8 8021B5F8 00000027 */  not       $zero, $zero
/* 4FB1DC 8021B5FC 00000002 */  srl       $zero, $zero, 0
/* 4FB1E0 8021B600 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB1E4 8021B604 00000014 */  dsllv     $zero, $zero, $zero
/* 4FB1E8 8021B608 00000027 */  not       $zero, $zero
/* 4FB1EC 8021B60C 00000002 */  srl       $zero, $zero, 0
/* 4FB1F0 8021B610 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FB1F4 8021B614 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB1F8 8021B618 00000043 */  sra       $zero, $zero, 1
/* 4FB1FC 8021B61C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB200 8021B620 8026A510 */  lb        $a2, -0x5af0($at)
/* 4FB204 8021B624 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB208 8021B628 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB20C 8021B62C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FB210 8021B630 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FB214 8021B634 00000043 */  sra       $zero, $zero, 1
/* 4FB218 8021B638 00000003 */  sra       $zero, $zero, 0
/* 4FB21C 8021B63C 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FB220 8021B640 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB224 8021B644 F24A8E80 */  scd       $t2, -0x7180($s2)
/* 4FB228 8021B648 00000043 */  sra       $zero, $zero, 1
/* 4FB22C 8021B64C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB230 8021B650 8027B624 */  lb        $a3, -0x49dc($at)
/* 4FB234 8021B654 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB238 8021B658 00000000 */  nop       
/* 4FB23C 8021B65C FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FB240 8021B660 00000004 */  sllv      $zero, $zero, $zero
/* 4FB244 8021B664 00000008 */  jr        $zero
/* 4FB248 8021B668 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB24C 8021B66C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB250 8021B670 00000043 */  sra       $zero, $zero, 1
/* 4FB254 8021B674 00000003 */  sra       $zero, $zero, 0
/* 4FB258 8021B678 8025385C */  lb        $a1, 0x385c($at)
/* 4FB25C 8021B67C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB260 8021B680 000020CA */  .byte     0x00, 0x00, 0x20, 0xca
/* 4FB264 8021B684 00000043 */  sra       $zero, $zero, 1
/* 4FB268 8021B688 00000004 */  sllv      $zero, $zero, $zero
/* 4FB26C 8021B68C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FB270 8021B690 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB274 8021B694 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB278 8021B698 004B0004 */  sllv      $zero, $t3, $v0
/* 4FB27C 8021B69C 00000008 */  jr        $zero
/* 4FB280 8021B6A0 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB284 8021B6A4 00000006 */  srlv      $zero, $zero, $zero
/* 4FB288 8021B6A8 00000008 */  jr        $zero
/* 4FB28C 8021B6AC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB290 8021B6B0 00000002 */  srl       $zero, $zero, 0
/* 4FB294 8021B6B4 00000043 */  sra       $zero, $zero, 1
/* 4FB298 8021B6B8 00000008 */  jr        $zero
/* 4FB29C 8021B6BC 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FB2A0 8021B6C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB2A4 8021B6C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB2A8 8021B6C8 00000000 */  nop       
/* 4FB2AC 8021B6CC 00000000 */  nop       
/* 4FB2B0 8021B6D0 80020328 */  lb        $v0, 0x328($zero)
/* 4FB2B4 8021B6D4 00000006 */  srlv      $zero, $zero, $zero
/* 4FB2B8 8021B6D8 00000020 */  add       $zero, $zero, $zero
/* 4FB2BC 8021B6DC 00000014 */  dsllv     $zero, $zero, $zero
/* 4FB2C0 8021B6E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB2C4 8021B6E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB2C8 8021B6E8 0000001D */  dmultu    $zero, $zero
/* 4FB2CC 8021B6EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB2D0 8021B6F0 00000000 */  nop       
/* 4FB2D4 8021B6F4 0000001D */  dmultu    $zero, $zero
/* 4FB2D8 8021B6F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB2DC 8021B6FC 00000002 */  srl       $zero, $zero, 0
/* 4FB2E0 8021B700 00000043 */  sra       $zero, $zero, 1
/* 4FB2E4 8021B704 00000002 */  srl       $zero, $zero, 0
/* 4FB2E8 8021B708 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FB2EC 8021B70C 00000002 */  srl       $zero, $zero, 0
/* 4FB2F0 8021B710 00000008 */  jr        $zero
/* 4FB2F4 8021B714 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB2F8 8021B718 00000014 */  dsllv     $zero, $zero, $zero
/* 4FB2FC 8021B71C 00000043 */  sra       $zero, $zero, 1
/* 4FB300 8021B720 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB304 8021B724 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4FB308 8021B728 00000046 */  rotrv     $zero, $zero, $zero
/* 4FB30C 8021B72C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB310 8021B730 8021AC20 */  lb        $at, -0x53e0($at)
/* 4FB314 8021B734 00000020 */  add       $zero, $zero, $zero
/* 4FB318 8021B738 00000000 */  nop       
/* 4FB31C 8021B73C 00000023 */  negu      $zero, $zero
/* 4FB320 8021B740 00000000 */  nop       
/* 4FB324 8021B744 00000043 */  sra       $zero, $zero, 1
/* 4FB328 8021B748 00000003 */  sra       $zero, $zero, 0
/* 4FB32C 8021B74C 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FB330 8021B750 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB334 8021B754 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB338 8021B758 00000043 */  sra       $zero, $zero, 1
/* 4FB33C 8021B75C 00000003 */  sra       $zero, $zero, 0
/* 4FB340 8021B760 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FB344 8021B764 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB348 8021B768 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB34C 8021B76C 00000002 */  srl       $zero, $zero, 0
/* 4FB350 8021B770 00000000 */  nop       
/* 4FB354 8021B774 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB358 8021B778 00000000 */  nop       
/* 4FB35C 8021B77C 00000024 */  and       $zero, $zero, $zero
/* 4FB360 8021B780 00000002 */  srl       $zero, $zero, 0
/* 4FB364 8021B784 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB368 8021B788 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB36C 8021B78C 00000043 */  sra       $zero, $zero, 1
/* 4FB370 8021B790 00000004 */  sllv      $zero, $zero, $zero
/* 4FB374 8021B794 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FB378 8021B798 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB37C 8021B79C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB380 8021B7A0 00000000 */  nop       
/* 4FB384 8021B7A4 00000043 */  sra       $zero, $zero, 1
/* 4FB388 8021B7A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB38C 8021B7AC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FB390 8021B7B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB394 8021B7B4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB398 8021B7B8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB39C 8021B7BC FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB3A0 8021B7C0 00000027 */  not       $zero, $zero
/* 4FB3A4 8021B7C4 00000002 */  srl       $zero, $zero, 0
/* 4FB3A8 8021B7C8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB3AC 8021B7CC 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 4FB3B0 8021B7D0 00000027 */  not       $zero, $zero
/* 4FB3B4 8021B7D4 00000002 */  srl       $zero, $zero, 0
/* 4FB3B8 8021B7D8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB3BC 8021B7DC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FB3C0 8021B7E0 00000043 */  sra       $zero, $zero, 1
/* 4FB3C4 8021B7E4 00000006 */  srlv      $zero, $zero, $zero
/* 4FB3C8 8021B7E8 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4FB3CC 8021B7EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB3D0 8021B7F0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB3D4 8021B7F4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB3D8 8021B7F8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB3DC 8021B7FC FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB3E0 8021B800 00000043 */  sra       $zero, $zero, 1
/* 4FB3E4 8021B804 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB3E8 8021B808 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FB3EC 8021B80C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB3F0 8021B810 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB3F4 8021B814 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB3F8 8021B818 00000000 */  nop       
/* 4FB3FC 8021B81C 00000043 */  sra       $zero, $zero, 1
/* 4FB400 8021B820 00000004 */  sllv      $zero, $zero, $zero
/* 4FB404 8021B824 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FB408 8021B828 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB40C 8021B82C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB410 8021B830 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FB414 8021B834 00000043 */  sra       $zero, $zero, 1
/* 4FB418 8021B838 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB41C 8021B83C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FB420 8021B840 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB424 8021B844 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB428 8021B848 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB42C 8021B84C FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB430 8021B850 00000027 */  not       $zero, $zero
/* 4FB434 8021B854 00000002 */  srl       $zero, $zero, 0
/* 4FB438 8021B858 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB43C 8021B85C 00000032 */  tlt       $zero, $zero
/* 4FB440 8021B860 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4FB444 8021B864 00000002 */  srl       $zero, $zero, 0
/* 4FB448 8021B868 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB44C 8021B86C 0000001E */  ddiv      $zero, $zero, $zero
/* 4FB450 8021B870 00000043 */  sra       $zero, $zero, 1
/* 4FB454 8021B874 00000004 */  sllv      $zero, $zero, $zero
/* 4FB458 8021B878 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FB45C 8021B87C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB460 8021B880 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB464 8021B884 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4FB468 8021B888 00000043 */  sra       $zero, $zero, 1
/* 4FB46C 8021B88C 00000004 */  sllv      $zero, $zero, $zero
/* 4FB470 8021B890 8026B74C */  lb        $a2, -0x48b4($at)
/* 4FB474 8021B894 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB478 8021B898 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB47C 8021B89C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4FB480 8021B8A0 00000043 */  sra       $zero, $zero, 1
/* 4FB484 8021B8A4 00000009 */  jr        $zero
/* 4FB488 8021B8A8 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FB48C 8021B8AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB490 8021B8B0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB494 8021B8B4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB498 8021B8B8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB49C 8021B8BC FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB4A0 8021B8C0 00000000 */  nop       
/* 4FB4A4 8021B8C4 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FB4A8 8021B8C8 00000000 */  nop       
/* 4FB4AC 8021B8CC 00000043 */  sra       $zero, $zero, 1
/* 4FB4B0 8021B8D0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB4B4 8021B8D4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FB4B8 8021B8D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB4BC 8021B8DC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FB4C0 8021B8E0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4FB4C4 8021B8E4 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FB4C8 8021B8E8 00000043 */  sra       $zero, $zero, 1
/* 4FB4CC 8021B8EC 00000006 */  srlv      $zero, $zero, $zero
/* 4FB4D0 8021B8F0 8026AB74 */  lb        $a2, -0x548c($at)
/* 4FB4D4 8021B8F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB4D8 8021B8F8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB4DC 8021B8FC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB4E0 8021B900 FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4FB4E4 8021B904 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4FB4E8 8021B908 00000043 */  sra       $zero, $zero, 1
/* 4FB4EC 8021B90C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB4F0 8021B910 802D45B0 */  lb        $t5, 0x45b0($at)
/* 4FB4F4 8021B914 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 4FB4F8 8021B918 000001C2 */  srl       $zero, $zero, 7
/* 4FB4FC 8021B91C 00000032 */  tlt       $zero, $zero
/* 4FB500 8021B920 00000000 */  nop       
/* 4FB504 8021B924 00000003 */  sra       $zero, $zero, 0
/* 4FB508 8021B928 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB50C 8021B92C 00000000 */  nop       
/* 4FB510 8021B930 00000043 */  sra       $zero, $zero, 1
/* 4FB514 8021B934 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB518 8021B938 802D462C */  lb        $t5, 0x462c($at)
/* 4FB51C 8021B93C 00000043 */  sra       $zero, $zero, 1
/* 4FB520 8021B940 00000007 */  srav      $zero, $zero, $zero
/* 4FB524 8021B944 8021823C */  lb        $at, -0x7dc4($at)
/* 4FB528 8021B948 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FB52C 8021B94C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FB530 8021B950 0000001E */  ddiv      $zero, $zero, $zero
/* 4FB534 8021B954 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB538 8021B958 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB53C 8021B95C FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4FB540 8021B960 00000043 */  sra       $zero, $zero, 1
/* 4FB544 8021B964 00000006 */  srlv      $zero, $zero, $zero
/* 4FB548 8021B968 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4FB54C 8021B96C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB550 8021B970 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB554 8021B974 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB558 8021B978 FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4FB55C 8021B97C FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4FB560 8021B980 0000000D */  break     
/* 4FB564 8021B984 00000002 */   srl      $zero, $zero, 0
/* 4FB568 8021B988 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FB56C 8021B98C FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB570 8021B990 00000043 */  sra       $zero, $zero, 1
/* 4FB574 8021B994 00000004 */  sllv      $zero, $zero, $zero
/* 4FB578 8021B998 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FB57C 8021B99C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB580 8021B9A0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB584 8021B9A4 000000B4 */  teq       $zero, $zero, 2
/* 4FB588 8021B9A8 00000012 */  mflo      $zero
/* 4FB58C 8021B9AC 00000000 */  nop       
/* 4FB590 8021B9B0 00000043 */  sra       $zero, $zero, 1
/* 4FB594 8021B9B4 00000004 */  sllv      $zero, $zero, $zero
/* 4FB598 8021B9B8 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FB59C 8021B9BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB5A0 8021B9C0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB5A4 8021B9C4 00000000 */  nop       
/* 4FB5A8 8021B9C8 00000013 */  mtlo      $zero
/* 4FB5AC 8021B9CC 00000000 */  nop       
/* 4FB5B0 8021B9D0 00000008 */  jr        $zero
/* 4FB5B4 8021B9D4 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB5B8 8021B9D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB5BC 8021B9DC 0000000A */  movz      $zero, $zero, $zero
/* 4FB5C0 8021B9E0 00000002 */  srl       $zero, $zero, 0
/* 4FB5C4 8021B9E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FB5C8 8021B9E8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB5CC 8021B9EC 00000004 */  sllv      $zero, $zero, $zero
/* 4FB5D0 8021B9F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB5D4 8021B9F4 00000000 */  nop       
/* 4FB5D8 8021B9F8 00000013 */  mtlo      $zero
/* 4FB5DC 8021B9FC 00000000 */  nop       
/* 4FB5E0 8021BA00 00000043 */  sra       $zero, $zero, 1
/* 4FB5E4 8021BA04 00000004 */  sllv      $zero, $zero, $zero
/* 4FB5E8 8021BA08 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FB5EC 8021BA0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB5F0 8021BA10 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB5F4 8021BA14 00000000 */  nop       
/* 4FB5F8 8021BA18 0000000A */  movz      $zero, $zero, $zero
/* 4FB5FC 8021BA1C 00000002 */  srl       $zero, $zero, 0
/* 4FB600 8021BA20 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB604 8021BA24 00000002 */  srl       $zero, $zero, 0
/* 4FB608 8021BA28 00000043 */  sra       $zero, $zero, 1
/* 4FB60C 8021BA2C 00000002 */  srl       $zero, $zero, 0
/* 4FB610 8021BA30 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FB614 8021BA34 00000008 */  jr        $zero
/* 4FB618 8021BA38 00000043 */   sra      $zero, $zero, 1
/* 4FB61C 8021BA3C 00000002 */  srl       $zero, $zero, 0
/* 4FB620 8021BA40 8024EC6C */  lb        $a0, -0x1394($at)
/* 4FB624 8021BA44 00000190 */  .byte     0x00, 0x00, 0x01, 0x90
/* 4FB628 8021BA48 00000043 */  sra       $zero, $zero, 1
/* 4FB62C 8021BA4C 00000002 */  srl       $zero, $zero, 0
/* 4FB630 8021BA50 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4FB634 8021BA54 0000001E */  ddiv      $zero, $zero, $zero
/* 4FB638 8021BA58 00000043 */  sra       $zero, $zero, 1
/* 4FB63C 8021BA5C 00000002 */  srl       $zero, $zero, 0
/* 4FB640 8021BA60 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4FB644 8021BA64 00000000 */  nop       
/* 4FB648 8021BA68 00000043 */  sra       $zero, $zero, 1
/* 4FB64C 8021BA6C 00000002 */  srl       $zero, $zero, 0
/* 4FB650 8021BA70 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4FB654 8021BA74 0000003C */  dsll32    $zero, $zero, 0
/* 4FB658 8021BA78 00000013 */  mtlo      $zero
/* 4FB65C 8021BA7C 00000000 */  nop       
/* 4FB660 8021BA80 00000043 */  sra       $zero, $zero, 1
/* 4FB664 8021BA84 00000004 */  sllv      $zero, $zero, $zero
/* 4FB668 8021BA88 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FB66C 8021BA8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB670 8021BA90 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB674 8021BA94 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FB678 8021BA98 00000043 */  sra       $zero, $zero, 1
/* 4FB67C 8021BA9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB680 8021BAA0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FB684 8021BAA4 00000000 */  nop       
/* 4FB688 8021BAA8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB68C 8021BAAC FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB690 8021BAB0 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB694 8021BAB4 00000027 */  not       $zero, $zero
/* 4FB698 8021BAB8 00000002 */  srl       $zero, $zero, 0
/* 4FB69C 8021BABC FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB6A0 8021BAC0 0000001E */  ddiv      $zero, $zero, $zero
/* 4FB6A4 8021BAC4 00000027 */  not       $zero, $zero
/* 4FB6A8 8021BAC8 00000002 */  srl       $zero, $zero, 0
/* 4FB6AC 8021BACC FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB6B0 8021BAD0 0000001E */  ddiv      $zero, $zero, $zero
/* 4FB6B4 8021BAD4 00000043 */  sra       $zero, $zero, 1
/* 4FB6B8 8021BAD8 00000004 */  sllv      $zero, $zero, $zero
/* 4FB6BC 8021BADC 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FB6C0 8021BAE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB6C4 8021BAE4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB6C8 8021BAE8 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4FB6CC 8021BAEC 00000043 */  sra       $zero, $zero, 1
/* 4FB6D0 8021BAF0 00000004 */  sllv      $zero, $zero, $zero
/* 4FB6D4 8021BAF4 8026B74C */  lb        $a2, -0x48b4($at)
/* 4FB6D8 8021BAF8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB6DC 8021BAFC FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB6E0 8021BB00 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4FB6E4 8021BB04 00000043 */  sra       $zero, $zero, 1
/* 4FB6E8 8021BB08 00000009 */  jr        $zero
/* 4FB6EC 8021BB0C 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FB6F0 8021BB10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB6F4 8021BB14 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB6F8 8021BB18 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FB6FC 8021BB1C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 4FB700 8021BB20 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 4FB704 8021BB24 00000000 */  nop       
/* 4FB708 8021BB28 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FB70C 8021BB2C 00000000 */  nop       
/* 4FB710 8021BB30 00000043 */  sra       $zero, $zero, 1
/* 4FB714 8021BB34 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB718 8021BB38 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FB71C 8021BB3C 00000000 */  nop       
/* 4FB720 8021BB40 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FB724 8021BB44 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 4FB728 8021BB48 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FB72C 8021BB4C 00000043 */  sra       $zero, $zero, 1
/* 4FB730 8021BB50 00000006 */  srlv      $zero, $zero, $zero
/* 4FB734 8021BB54 8026AB74 */  lb        $a2, -0x548c($at)
/* 4FB738 8021BB58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB73C 8021BB5C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB740 8021BB60 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB744 8021BB64 FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4FB748 8021BB68 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4FB74C 8021BB6C 00000043 */  sra       $zero, $zero, 1
/* 4FB750 8021BB70 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB754 8021BB74 802D45B0 */  lb        $t5, 0x45b0($at)
/* 4FB758 8021BB78 FFFFFFA6 */  sd        $ra, -0x5a($ra)
/* 4FB75C 8021BB7C FFFFFD30 */  sd        $ra, -0x2d0($ra)
/* 4FB760 8021BB80 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FB764 8021BB84 00000000 */  nop       
/* 4FB768 8021BB88 00000003 */  sra       $zero, $zero, 0
/* 4FB76C 8021BB8C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB770 8021BB90 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB774 8021BB94 00000043 */  sra       $zero, $zero, 1
/* 4FB778 8021BB98 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB77C 8021BB9C 802D462C */  lb        $t5, 0x462c($at)
/* 4FB780 8021BBA0 00000043 */  sra       $zero, $zero, 1
/* 4FB784 8021BBA4 00000007 */  srav      $zero, $zero, $zero
/* 4FB788 8021BBA8 8021823C */  lb        $at, -0x7dc4($at)
/* 4FB78C 8021BBAC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FB790 8021BBB0 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FB794 8021BBB4 0000001E */  ddiv      $zero, $zero, $zero
/* 4FB798 8021BBB8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB79C 8021BBBC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB7A0 8021BBC0 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4FB7A4 8021BBC4 00000043 */  sra       $zero, $zero, 1
/* 4FB7A8 8021BBC8 00000006 */  srlv      $zero, $zero, $zero
/* 4FB7AC 8021BBCC 8026AF18 */  lb        $a2, -0x50e8($at)
/* 4FB7B0 8021BBD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB7B4 8021BBD4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB7B8 8021BBD8 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB7BC 8021BBDC FE363C87 */  sd        $s6, 0x3c87($s1)
/* 4FB7C0 8021BBE0 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 4FB7C4 8021BBE4 0000000D */  break     
/* 4FB7C8 8021BBE8 00000002 */   srl      $zero, $zero, 0
/* 4FB7CC 8021BBEC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FB7D0 8021BBF0 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 4FB7D4 8021BBF4 00000043 */  sra       $zero, $zero, 1
/* 4FB7D8 8021BBF8 00000004 */  sllv      $zero, $zero, $zero
/* 4FB7DC 8021BBFC 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FB7E0 8021BC00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB7E4 8021BC04 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB7E8 8021BC08 000000B4 */  teq       $zero, $zero, 2
/* 4FB7EC 8021BC0C 00000012 */  mflo      $zero
/* 4FB7F0 8021BC10 00000000 */  nop       
/* 4FB7F4 8021BC14 00000043 */  sra       $zero, $zero, 1
/* 4FB7F8 8021BC18 00000004 */  sllv      $zero, $zero, $zero
/* 4FB7FC 8021BC1C 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FB800 8021BC20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB804 8021BC24 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 4FB808 8021BC28 00000000 */  nop       
/* 4FB80C 8021BC2C 00000013 */  mtlo      $zero
/* 4FB810 8021BC30 00000000 */  nop       
/* 4FB814 8021BC34 00000008 */  jr        $zero
/* 4FB818 8021BC38 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB81C 8021BC3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB820 8021BC40 0000000A */  movz      $zero, $zero, $zero
/* 4FB824 8021BC44 00000002 */  srl       $zero, $zero, 0
/* 4FB828 8021BC48 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FB82C 8021BC4C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB830 8021BC50 00000004 */  sllv      $zero, $zero, $zero
/* 4FB834 8021BC54 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB838 8021BC58 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB83C 8021BC5C 00000013 */  mtlo      $zero
/* 4FB840 8021BC60 00000000 */  nop       
/* 4FB844 8021BC64 00000002 */  srl       $zero, $zero, 0
/* 4FB848 8021BC68 00000000 */  nop       
/* 4FB84C 8021BC6C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB850 8021BC70 00000000 */  nop       
/* 4FB854 8021BC74 00000043 */  sra       $zero, $zero, 1
/* 4FB858 8021BC78 00000003 */  sra       $zero, $zero, 0
/* 4FB85C 8021BC7C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FB860 8021BC80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB864 8021BC84 00000000 */  nop       
/* 4FB868 8021BC88 00000043 */  sra       $zero, $zero, 1
/* 4FB86C 8021BC8C 00000003 */  sra       $zero, $zero, 0
/* 4FB870 8021BC90 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FB874 8021BC94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB878 8021BC98 00000000 */  nop       
/* 4FB87C 8021BC9C 00000043 */  sra       $zero, $zero, 1
/* 4FB880 8021BCA0 00000003 */  sra       $zero, $zero, 0
/* 4FB884 8021BCA4 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4FB888 8021BCA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB88C 8021BCAC 00000000 */  nop       
/* 4FB890 8021BCB0 00000043 */  sra       $zero, $zero, 1
/* 4FB894 8021BCB4 00000002 */  srl       $zero, $zero, 0
/* 4FB898 8021BCB8 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FB89C 8021BCBC 0000003F */  dsra32    $zero, $zero, 0
/* 4FB8A0 8021BCC0 00000043 */  sra       $zero, $zero, 1
/* 4FB8A4 8021BCC4 00000002 */  srl       $zero, $zero, 0
/* 4FB8A8 8021BCC8 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4FB8AC 8021BCCC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB8B0 8021BCD0 00000043 */  sra       $zero, $zero, 1
/* 4FB8B4 8021BCD4 00000004 */  sllv      $zero, $zero, $zero
/* 4FB8B8 8021BCD8 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4FB8BC 8021BCDC FFFFFFFF */  sd        $ra, -1($ra)
/* 4FB8C0 8021BCE0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB8C4 8021BCE4 00000000 */  nop       
/* 4FB8C8 8021BCE8 00000043 */  sra       $zero, $zero, 1
/* 4FB8CC 8021BCEC 00000006 */  srlv      $zero, $zero, $zero
/* 4FB8D0 8021BCF0 8026FA00 */  lb        $a2, -0x600($at)
/* 4FB8D4 8021BCF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB8D8 8021BCF8 00000002 */  srl       $zero, $zero, 0
/* 4FB8DC 8021BCFC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB8E0 8021BD00 00000000 */  nop       
/* 4FB8E4 8021BD04 00000000 */  nop       
/* 4FB8E8 8021BD08 00000043 */  sra       $zero, $zero, 1
/* 4FB8EC 8021BD0C 00000006 */  srlv      $zero, $zero, $zero
/* 4FB8F0 8021BD10 8026FA00 */  lb        $a2, -0x600($at)
/* 4FB8F4 8021BD14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB8F8 8021BD18 00000003 */  sra       $zero, $zero, 0
/* 4FB8FC 8021BD1C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB900 8021BD20 00000000 */  nop       
/* 4FB904 8021BD24 00000000 */  nop       
/* 4FB908 8021BD28 00000043 */  sra       $zero, $zero, 1
/* 4FB90C 8021BD2C 00000006 */  srlv      $zero, $zero, $zero
/* 4FB910 8021BD30 8026FA00 */  lb        $a2, -0x600($at)
/* 4FB914 8021BD34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB918 8021BD38 00000004 */  sllv      $zero, $zero, $zero
/* 4FB91C 8021BD3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB920 8021BD40 00000000 */  nop       
/* 4FB924 8021BD44 00000000 */  nop       
/* 4FB928 8021BD48 00000043 */  sra       $zero, $zero, 1
/* 4FB92C 8021BD4C 00000006 */  srlv      $zero, $zero, $zero
/* 4FB930 8021BD50 8026FA00 */  lb        $a2, -0x600($at)
/* 4FB934 8021BD54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB938 8021BD58 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FB93C 8021BD5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB940 8021BD60 00000000 */  nop       
/* 4FB944 8021BD64 00000000 */  nop       
/* 4FB948 8021BD68 00000043 */  sra       $zero, $zero, 1
/* 4FB94C 8021BD6C 00000006 */  srlv      $zero, $zero, $zero
/* 4FB950 8021BD70 8026FA00 */  lb        $a2, -0x600($at)
/* 4FB954 8021BD74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB958 8021BD78 00000006 */  srlv      $zero, $zero, $zero
/* 4FB95C 8021BD7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB960 8021BD80 00000000 */  nop       
/* 4FB964 8021BD84 00000000 */  nop       
/* 4FB968 8021BD88 00000043 */  sra       $zero, $zero, 1
/* 4FB96C 8021BD8C 00000003 */  sra       $zero, $zero, 0
/* 4FB970 8021BD90 8025385C */  lb        $a1, 0x385c($at)
/* 4FB974 8021BD94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB978 8021BD98 000020CC */  syscall   0x83
/* 4FB97C 8021BD9C 00000043 */  sra       $zero, $zero, 1
/* 4FB980 8021BDA0 00000003 */  sra       $zero, $zero, 0
/* 4FB984 8021BDA4 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4FB988 8021BDA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB98C 8021BDAC 000000B4 */  teq       $zero, $zero, 2
/* 4FB990 8021BDB0 00000043 */  sra       $zero, $zero, 1
/* 4FB994 8021BDB4 00000004 */  sllv      $zero, $zero, $zero
/* 4FB998 8021BDB8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FB99C 8021BDBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB9A0 8021BDC0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB9A4 8021BDC4 004B0005 */  lsa       $zero, $v0, $t3, 1
/* 4FB9A8 8021BDC8 00000008 */  jr        $zero
/* 4FB9AC 8021BDCC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FB9B0 8021BDD0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4FB9B4 8021BDD4 00000043 */  sra       $zero, $zero, 1
/* 4FB9B8 8021BDD8 00000004 */  sllv      $zero, $zero, $zero
/* 4FB9BC 8021BDDC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FB9C0 8021BDE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB9C4 8021BDE4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FB9C8 8021BDE8 004B0001 */  .byte     0x00, 0x4b, 0x00, 0x01
/* 4FB9CC 8021BDEC 00000043 */  sra       $zero, $zero, 1
/* 4FB9D0 8021BDF0 00000003 */  sra       $zero, $zero, 0
/* 4FB9D4 8021BDF4 8026B358 */  lb        $a2, -0x4ca8($at)
/* 4FB9D8 8021BDF8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FB9DC 8021BDFC 00000000 */  nop       
/* 4FB9E0 8021BE00 00000043 */  sra       $zero, $zero, 1
/* 4FB9E4 8021BE04 00000002 */  srl       $zero, $zero, 0
/* 4FB9E8 8021BE08 802D6150 */  lb        $t5, 0x6150($at)
/* 4FB9EC 8021BE0C 00000358 */  .byte     0x00, 0x00, 0x03, 0x58
/* 4FB9F0 8021BE10 00000024 */  and       $zero, $zero, $zero
/* 4FB9F4 8021BE14 00000002 */  srl       $zero, $zero, 0
/* 4FB9F8 8021BE18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FB9FC 8021BE1C 00000002 */  srl       $zero, $zero, 0
/* 4FBA00 8021BE20 00000045 */  lsa       $zero, $zero, $zero, 2
/* 4FBA04 8021BE24 00000002 */  srl       $zero, $zero, 0
/* 4FBA08 8021BE28 8021B77C */  lb        $at, -0x4884($at)
/* 4FBA0C 8021BE2C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FBA10 8021BE30 00000008 */  jr        $zero
/* 4FBA14 8021BE34 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBA18 8021BE38 0000000B */  movn      $zero, $zero, $zero
/* 4FBA1C 8021BE3C 00000024 */  and       $zero, $zero, $zero
/* 4FBA20 8021BE40 00000002 */  srl       $zero, $zero, 0
/* 4FBA24 8021BE44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBA28 8021BE48 00000003 */  sra       $zero, $zero, 0
/* 4FBA2C 8021BE4C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4FBA30 8021BE50 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBA34 8021BE54 8021B77C */  lb        $at, -0x4884($at)
/* 4FBA38 8021BE58 00000008 */  jr        $zero
/* 4FBA3C 8021BE5C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBA40 8021BE60 0000000B */  movn      $zero, $zero, $zero
/* 4FBA44 8021BE64 00000024 */  and       $zero, $zero, $zero
/* 4FBA48 8021BE68 00000002 */  srl       $zero, $zero, 0
/* 4FBA4C 8021BE6C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBA50 8021BE70 00000004 */  sllv      $zero, $zero, $zero
/* 4FBA54 8021BE74 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4FBA58 8021BE78 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBA5C 8021BE7C 8021B77C */  lb        $at, -0x4884($at)
/* 4FBA60 8021BE80 00000008 */  jr        $zero
/* 4FBA64 8021BE84 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBA68 8021BE88 0000000B */  movn      $zero, $zero, $zero
/* 4FBA6C 8021BE8C 00000024 */  and       $zero, $zero, $zero
/* 4FBA70 8021BE90 00000002 */  srl       $zero, $zero, 0
/* 4FBA74 8021BE94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBA78 8021BE98 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBA7C 8021BE9C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4FBA80 8021BEA0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBA84 8021BEA4 8021B77C */  lb        $at, -0x4884($at)
/* 4FBA88 8021BEA8 00000008 */  jr        $zero
/* 4FBA8C 8021BEAC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBA90 8021BEB0 0000000B */  movn      $zero, $zero, $zero
/* 4FBA94 8021BEB4 00000024 */  and       $zero, $zero, $zero
/* 4FBA98 8021BEB8 00000002 */  srl       $zero, $zero, 0
/* 4FBA9C 8021BEBC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBAA0 8021BEC0 00000006 */  srlv      $zero, $zero, $zero
/* 4FBAA4 8021BEC4 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4FBAA8 8021BEC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBAAC 8021BECC 8021B77C */  lb        $at, -0x4884($at)
/* 4FBAB0 8021BED0 00000003 */  sra       $zero, $zero, 0
/* 4FBAB4 8021BED4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBAB8 8021BED8 00000000 */  nop       
/* 4FBABC 8021BEDC 00000055 */  dlsa      $zero, $zero, $zero, 2
/* 4FBAC0 8021BEE0 00000002 */  srl       $zero, $zero, 0
/* 4FBAC4 8021BEE4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FBAC8 8021BEE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBACC 8021BEEC 00000008 */  jr        $zero
/* 4FBAD0 8021BEF0 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBAD4 8021BEF4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBAD8 8021BEF8 0000000A */  movz      $zero, $zero, $zero
/* 4FBADC 8021BEFC 00000002 */  srl       $zero, $zero, 0
/* 4FBAE0 8021BF00 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBAE4 8021BF04 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBAE8 8021BF08 00000004 */  sllv      $zero, $zero, $zero
/* 4FBAEC 8021BF0C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBAF0 8021BF10 00000000 */  nop       
/* 4FBAF4 8021BF14 00000013 */  mtlo      $zero
/* 4FBAF8 8021BF18 00000000 */  nop       
/* 4FBAFC 8021BF1C 00000043 */  sra       $zero, $zero, 1
/* 4FBB00 8021BF20 00000007 */  srav      $zero, $zero, $zero
/* 4FBB04 8021BF24 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4FBB08 8021BF28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBB0C 8021BF2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBB10 8021BF30 00000000 */  nop       
/* 4FBB14 8021BF34 00000000 */  nop       
/* 4FBB18 8021BF38 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBB1C 8021BF3C 00000010 */  mfhi      $zero
/* 4FBB20 8021BF40 00000014 */  dsllv     $zero, $zero, $zero
/* 4FBB24 8021BF44 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBB28 8021BF48 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBB2C 8021BF4C 0000001D */  dmultu    $zero, $zero
/* 4FBB30 8021BF50 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBB34 8021BF54 00000006 */  srlv      $zero, $zero, $zero
/* 4FBB38 8021BF58 0000001D */  dmultu    $zero, $zero
/* 4FBB3C 8021BF5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBB40 8021BF60 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBB44 8021BF64 00000024 */  and       $zero, $zero, $zero
/* 4FBB48 8021BF68 00000002 */  srl       $zero, $zero, 0
/* 4FBB4C 8021BF6C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FBB50 8021BF70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBB54 8021BF74 00000056 */  drotrv    $zero, $zero, $zero
/* 4FBB58 8021BF78 00000000 */  nop       
/* 4FBB5C 8021BF7C 00000043 */  sra       $zero, $zero, 1
/* 4FBB60 8021BF80 00000004 */  sllv      $zero, $zero, $zero
/* 4FBB64 8021BF84 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FBB68 8021BF88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBB6C 8021BF8C 00000002 */  srl       $zero, $zero, 0
/* 4FBB70 8021BF90 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FBB74 8021BF94 00000043 */  sra       $zero, $zero, 1
/* 4FBB78 8021BF98 00000004 */  sllv      $zero, $zero, $zero
/* 4FBB7C 8021BF9C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FBB80 8021BFA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBB84 8021BFA4 00000002 */  srl       $zero, $zero, 0
/* 4FBB88 8021BFA8 004B0004 */  sllv      $zero, $t3, $v0
/* 4FBB8C 8021BFAC 00000043 */  sra       $zero, $zero, 1
/* 4FBB90 8021BFB0 00000002 */  srl       $zero, $zero, 0
/* 4FBB94 8021BFB4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FBB98 8021BFB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBB9C 8021BFBC 00000043 */  sra       $zero, $zero, 1
/* 4FBBA0 8021BFC0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBBA4 8021BFC4 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FBBA8 8021BFC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBBAC 8021BFCC FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4FBBB0 8021BFD0 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 4FBBB4 8021BFD4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBBB8 8021BFD8 00000043 */  sra       $zero, $zero, 1
/* 4FBBBC 8021BFDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBBC0 8021BFE0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FBBC4 8021BFE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBBC8 8021BFE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBBCC 8021BFEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBBD0 8021BFF0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBBD4 8021BFF4 00000043 */  sra       $zero, $zero, 1
/* 4FBBD8 8021BFF8 00000004 */  sllv      $zero, $zero, $zero
/* 4FBBDC 8021BFFC 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FBBE0 8021C000 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBBE4 8021C004 00000002 */  srl       $zero, $zero, 0
/* 4FBBE8 8021C008 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FBBEC 8021C00C 00000043 */  sra       $zero, $zero, 1
/* 4FBBF0 8021C010 00000009 */  jr        $zero
/* 4FBBF4 8021C014 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FBBF8 8021C018 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBBFC 8021C01C 00000002 */  srl       $zero, $zero, 0
/* 4FBC00 8021C020 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBC04 8021C024 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBC08 8021C028 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBC0C 8021C02C 00000000 */  nop       
/* 4FBC10 8021C030 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FBC14 8021C034 00000000 */  nop       
/* 4FBC18 8021C038 00000043 */  sra       $zero, $zero, 1
/* 4FBC1C 8021C03C 00000004 */  sllv      $zero, $zero, $zero
/* 4FBC20 8021C040 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FBC24 8021C044 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBC28 8021C048 00000002 */  srl       $zero, $zero, 0
/* 4FBC2C 8021C04C 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FBC30 8021C050 00000043 */  sra       $zero, $zero, 1
/* 4FBC34 8021C054 00000004 */  sllv      $zero, $zero, $zero
/* 4FBC38 8021C058 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FBC3C 8021C05C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBC40 8021C060 00000002 */  srl       $zero, $zero, 0
/* 4FBC44 8021C064 000000B4 */  teq       $zero, $zero, 2
/* 4FBC48 8021C068 00000043 */  sra       $zero, $zero, 1
/* 4FBC4C 8021C06C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBC50 8021C070 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FBC54 8021C074 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBC58 8021C078 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBC5C 8021C07C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBC60 8021C080 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBC64 8021C084 00000027 */  not       $zero, $zero
/* 4FBC68 8021C088 00000002 */  srl       $zero, $zero, 0
/* 4FBC6C 8021C08C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBC70 8021C090 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FBC74 8021C094 00000027 */  not       $zero, $zero
/* 4FBC78 8021C098 00000002 */  srl       $zero, $zero, 0
/* 4FBC7C 8021C09C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBC80 8021C0A0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FBC84 8021C0A4 00000043 */  sra       $zero, $zero, 1
/* 4FBC88 8021C0A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBC8C 8021C0AC 8026EE88 */  lb        $a2, -0x1178($at)
/* 4FBC90 8021C0B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBC94 8021C0B4 00000002 */  srl       $zero, $zero, 0
/* 4FBC98 8021C0B8 00000000 */  nop       
/* 4FBC9C 8021C0BC 00000002 */  srl       $zero, $zero, 0
/* 4FBCA0 8021C0C0 00000043 */  sra       $zero, $zero, 1
/* 4FBCA4 8021C0C4 00000009 */  jr        $zero
/* 4FBCA8 8021C0C8 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FBCAC 8021C0CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBCB0 8021C0D0 00000002 */  srl       $zero, $zero, 0
/* 4FBCB4 8021C0D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBCB8 8021C0D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBCBC 8021C0DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBCC0 8021C0E0 00000000 */  nop       
/* 4FBCC4 8021C0E4 0000000A */  movz      $zero, $zero, $zero
/* 4FBCC8 8021C0E8 00000000 */  nop       
/* 4FBCCC 8021C0EC 00000043 */  sra       $zero, $zero, 1
/* 4FBCD0 8021C0F0 00000004 */  sllv      $zero, $zero, $zero
/* 4FBCD4 8021C0F4 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4FBCD8 8021C0F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBCDC 8021C0FC 00000002 */  srl       $zero, $zero, 0
/* 4FBCE0 8021C100 00000000 */  nop       
/* 4FBCE4 8021C104 00000043 */  sra       $zero, $zero, 1
/* 4FBCE8 8021C108 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBCEC 8021C10C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FBCF0 8021C110 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBCF4 8021C114 00000002 */  srl       $zero, $zero, 0
/* 4FBCF8 8021C118 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBCFC 8021C11C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBD00 8021C120 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FBD04 8021C124 00000000 */  nop       
/* 4FBD08 8021C128 00000008 */  jr        $zero
/* 4FBD0C 8021C12C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBD10 8021C130 0000000B */  movn      $zero, $zero, $zero
/* 4FBD14 8021C134 00000056 */  drotrv    $zero, $zero, $zero
/* 4FBD18 8021C138 00000000 */  nop       
/* 4FBD1C 8021C13C 00000043 */  sra       $zero, $zero, 1
/* 4FBD20 8021C140 00000004 */  sllv      $zero, $zero, $zero
/* 4FBD24 8021C144 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FBD28 8021C148 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBD2C 8021C14C 00000003 */  sra       $zero, $zero, 0
/* 4FBD30 8021C150 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FBD34 8021C154 00000043 */  sra       $zero, $zero, 1
/* 4FBD38 8021C158 00000004 */  sllv      $zero, $zero, $zero
/* 4FBD3C 8021C15C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FBD40 8021C160 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBD44 8021C164 00000003 */  sra       $zero, $zero, 0
/* 4FBD48 8021C168 004B0004 */  sllv      $zero, $t3, $v0
/* 4FBD4C 8021C16C 00000043 */  sra       $zero, $zero, 1
/* 4FBD50 8021C170 00000002 */  srl       $zero, $zero, 0
/* 4FBD54 8021C174 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FBD58 8021C178 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBD5C 8021C17C 00000043 */  sra       $zero, $zero, 1
/* 4FBD60 8021C180 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBD64 8021C184 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FBD68 8021C188 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBD6C 8021C18C FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4FBD70 8021C190 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 4FBD74 8021C194 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBD78 8021C198 00000043 */  sra       $zero, $zero, 1
/* 4FBD7C 8021C19C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBD80 8021C1A0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FBD84 8021C1A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBD88 8021C1A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBD8C 8021C1AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBD90 8021C1B0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBD94 8021C1B4 00000043 */  sra       $zero, $zero, 1
/* 4FBD98 8021C1B8 00000004 */  sllv      $zero, $zero, $zero
/* 4FBD9C 8021C1BC 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FBDA0 8021C1C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBDA4 8021C1C4 00000003 */  sra       $zero, $zero, 0
/* 4FBDA8 8021C1C8 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FBDAC 8021C1CC 00000043 */  sra       $zero, $zero, 1
/* 4FBDB0 8021C1D0 00000009 */  jr        $zero
/* 4FBDB4 8021C1D4 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FBDB8 8021C1D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBDBC 8021C1DC 00000003 */  sra       $zero, $zero, 0
/* 4FBDC0 8021C1E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBDC4 8021C1E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBDC8 8021C1E8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBDCC 8021C1EC 00000000 */  nop       
/* 4FBDD0 8021C1F0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FBDD4 8021C1F4 00000000 */  nop       
/* 4FBDD8 8021C1F8 00000043 */  sra       $zero, $zero, 1
/* 4FBDDC 8021C1FC 00000004 */  sllv      $zero, $zero, $zero
/* 4FBDE0 8021C200 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FBDE4 8021C204 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBDE8 8021C208 00000003 */  sra       $zero, $zero, 0
/* 4FBDEC 8021C20C 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FBDF0 8021C210 00000043 */  sra       $zero, $zero, 1
/* 4FBDF4 8021C214 00000004 */  sllv      $zero, $zero, $zero
/* 4FBDF8 8021C218 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FBDFC 8021C21C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBE00 8021C220 00000003 */  sra       $zero, $zero, 0
/* 4FBE04 8021C224 000000B4 */  teq       $zero, $zero, 2
/* 4FBE08 8021C228 00000043 */  sra       $zero, $zero, 1
/* 4FBE0C 8021C22C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBE10 8021C230 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FBE14 8021C234 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBE18 8021C238 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBE1C 8021C23C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBE20 8021C240 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBE24 8021C244 00000027 */  not       $zero, $zero
/* 4FBE28 8021C248 00000002 */  srl       $zero, $zero, 0
/* 4FBE2C 8021C24C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBE30 8021C250 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FBE34 8021C254 00000027 */  not       $zero, $zero
/* 4FBE38 8021C258 00000002 */  srl       $zero, $zero, 0
/* 4FBE3C 8021C25C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBE40 8021C260 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FBE44 8021C264 00000043 */  sra       $zero, $zero, 1
/* 4FBE48 8021C268 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBE4C 8021C26C 8026EE88 */  lb        $a2, -0x1178($at)
/* 4FBE50 8021C270 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBE54 8021C274 00000003 */  sra       $zero, $zero, 0
/* 4FBE58 8021C278 00000000 */  nop       
/* 4FBE5C 8021C27C 00000002 */  srl       $zero, $zero, 0
/* 4FBE60 8021C280 00000043 */  sra       $zero, $zero, 1
/* 4FBE64 8021C284 00000009 */  jr        $zero
/* 4FBE68 8021C288 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FBE6C 8021C28C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBE70 8021C290 00000003 */  sra       $zero, $zero, 0
/* 4FBE74 8021C294 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBE78 8021C298 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBE7C 8021C29C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBE80 8021C2A0 00000000 */  nop       
/* 4FBE84 8021C2A4 0000000A */  movz      $zero, $zero, $zero
/* 4FBE88 8021C2A8 00000000 */  nop       
/* 4FBE8C 8021C2AC 00000043 */  sra       $zero, $zero, 1
/* 4FBE90 8021C2B0 00000004 */  sllv      $zero, $zero, $zero
/* 4FBE94 8021C2B4 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4FBE98 8021C2B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBE9C 8021C2BC 00000003 */  sra       $zero, $zero, 0
/* 4FBEA0 8021C2C0 00000000 */  nop       
/* 4FBEA4 8021C2C4 00000043 */  sra       $zero, $zero, 1
/* 4FBEA8 8021C2C8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBEAC 8021C2CC 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FBEB0 8021C2D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBEB4 8021C2D4 00000003 */  sra       $zero, $zero, 0
/* 4FBEB8 8021C2D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBEBC 8021C2DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBEC0 8021C2E0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FBEC4 8021C2E4 00000000 */  nop       
/* 4FBEC8 8021C2E8 00000008 */  jr        $zero
/* 4FBECC 8021C2EC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FBED0 8021C2F0 0000000B */  movn      $zero, $zero, $zero
/* 4FBED4 8021C2F4 00000056 */  drotrv    $zero, $zero, $zero
/* 4FBED8 8021C2F8 00000000 */  nop       
/* 4FBEDC 8021C2FC 00000043 */  sra       $zero, $zero, 1
/* 4FBEE0 8021C300 00000004 */  sllv      $zero, $zero, $zero
/* 4FBEE4 8021C304 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FBEE8 8021C308 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBEEC 8021C30C 00000004 */  sllv      $zero, $zero, $zero
/* 4FBEF0 8021C310 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FBEF4 8021C314 00000043 */  sra       $zero, $zero, 1
/* 4FBEF8 8021C318 00000004 */  sllv      $zero, $zero, $zero
/* 4FBEFC 8021C31C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FBF00 8021C320 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBF04 8021C324 00000004 */  sllv      $zero, $zero, $zero
/* 4FBF08 8021C328 004B0004 */  sllv      $zero, $t3, $v0
/* 4FBF0C 8021C32C 00000043 */  sra       $zero, $zero, 1
/* 4FBF10 8021C330 00000002 */  srl       $zero, $zero, 0
/* 4FBF14 8021C334 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FBF18 8021C338 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBF1C 8021C33C 00000043 */  sra       $zero, $zero, 1
/* 4FBF20 8021C340 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBF24 8021C344 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FBF28 8021C348 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBF2C 8021C34C FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4FBF30 8021C350 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 4FBF34 8021C354 00000001 */  movf      $zero, $zero, $fcc0
/* 4FBF38 8021C358 00000043 */  sra       $zero, $zero, 1
/* 4FBF3C 8021C35C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBF40 8021C360 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FBF44 8021C364 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBF48 8021C368 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBF4C 8021C36C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBF50 8021C370 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBF54 8021C374 00000043 */  sra       $zero, $zero, 1
/* 4FBF58 8021C378 00000004 */  sllv      $zero, $zero, $zero
/* 4FBF5C 8021C37C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FBF60 8021C380 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBF64 8021C384 00000004 */  sllv      $zero, $zero, $zero
/* 4FBF68 8021C388 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FBF6C 8021C38C 00000043 */  sra       $zero, $zero, 1
/* 4FBF70 8021C390 00000009 */  jr        $zero
/* 4FBF74 8021C394 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FBF78 8021C398 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBF7C 8021C39C 00000004 */  sllv      $zero, $zero, $zero
/* 4FBF80 8021C3A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBF84 8021C3A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBF88 8021C3A8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBF8C 8021C3AC 00000000 */  nop       
/* 4FBF90 8021C3B0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FBF94 8021C3B4 00000000 */  nop       
/* 4FBF98 8021C3B8 00000043 */  sra       $zero, $zero, 1
/* 4FBF9C 8021C3BC 00000004 */  sllv      $zero, $zero, $zero
/* 4FBFA0 8021C3C0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FBFA4 8021C3C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBFA8 8021C3C8 00000004 */  sllv      $zero, $zero, $zero
/* 4FBFAC 8021C3CC 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FBFB0 8021C3D0 00000043 */  sra       $zero, $zero, 1
/* 4FBFB4 8021C3D4 00000004 */  sllv      $zero, $zero, $zero
/* 4FBFB8 8021C3D8 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FBFBC 8021C3DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBFC0 8021C3E0 00000004 */  sllv      $zero, $zero, $zero
/* 4FBFC4 8021C3E4 000000B4 */  teq       $zero, $zero, 2
/* 4FBFC8 8021C3E8 00000043 */  sra       $zero, $zero, 1
/* 4FBFCC 8021C3EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FBFD0 8021C3F0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FBFD4 8021C3F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FBFD8 8021C3F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FBFDC 8021C3FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBFE0 8021C400 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FBFE4 8021C404 00000027 */  not       $zero, $zero
/* 4FBFE8 8021C408 00000002 */  srl       $zero, $zero, 0
/* 4FBFEC 8021C40C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FBFF0 8021C410 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FBFF4 8021C414 00000027 */  not       $zero, $zero
/* 4FBFF8 8021C418 00000002 */  srl       $zero, $zero, 0
/* 4FBFFC 8021C41C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC000 8021C420 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC004 8021C424 00000043 */  sra       $zero, $zero, 1
/* 4FC008 8021C428 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC00C 8021C42C 8026EE88 */  lb        $a2, -0x1178($at)
/* 4FC010 8021C430 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC014 8021C434 00000004 */  sllv      $zero, $zero, $zero
/* 4FC018 8021C438 00000000 */  nop       
/* 4FC01C 8021C43C 00000002 */  srl       $zero, $zero, 0
/* 4FC020 8021C440 00000043 */  sra       $zero, $zero, 1
/* 4FC024 8021C444 00000009 */  jr        $zero
/* 4FC028 8021C448 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC02C 8021C44C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC030 8021C450 00000004 */  sllv      $zero, $zero, $zero
/* 4FC034 8021C454 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC038 8021C458 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC03C 8021C45C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC040 8021C460 00000000 */  nop       
/* 4FC044 8021C464 0000000A */  movz      $zero, $zero, $zero
/* 4FC048 8021C468 00000000 */  nop       
/* 4FC04C 8021C46C 00000043 */  sra       $zero, $zero, 1
/* 4FC050 8021C470 00000004 */  sllv      $zero, $zero, $zero
/* 4FC054 8021C474 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4FC058 8021C478 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC05C 8021C47C 00000004 */  sllv      $zero, $zero, $zero
/* 4FC060 8021C480 00000000 */  nop       
/* 4FC064 8021C484 00000043 */  sra       $zero, $zero, 1
/* 4FC068 8021C488 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC06C 8021C48C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FC070 8021C490 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC074 8021C494 00000004 */  sllv      $zero, $zero, $zero
/* 4FC078 8021C498 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC07C 8021C49C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC080 8021C4A0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FC084 8021C4A4 00000000 */  nop       
/* 4FC088 8021C4A8 00000008 */  jr        $zero
/* 4FC08C 8021C4AC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC090 8021C4B0 0000000B */  movn      $zero, $zero, $zero
/* 4FC094 8021C4B4 00000056 */  drotrv    $zero, $zero, $zero
/* 4FC098 8021C4B8 00000000 */  nop       
/* 4FC09C 8021C4BC 00000043 */  sra       $zero, $zero, 1
/* 4FC0A0 8021C4C0 00000004 */  sllv      $zero, $zero, $zero
/* 4FC0A4 8021C4C4 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FC0A8 8021C4C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC0AC 8021C4CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC0B0 8021C4D0 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FC0B4 8021C4D4 00000043 */  sra       $zero, $zero, 1
/* 4FC0B8 8021C4D8 00000004 */  sllv      $zero, $zero, $zero
/* 4FC0BC 8021C4DC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC0C0 8021C4E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC0C4 8021C4E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC0C8 8021C4E8 004B0004 */  sllv      $zero, $t3, $v0
/* 4FC0CC 8021C4EC 00000043 */  sra       $zero, $zero, 1
/* 4FC0D0 8021C4F0 00000002 */  srl       $zero, $zero, 0
/* 4FC0D4 8021C4F4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC0D8 8021C4F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC0DC 8021C4FC 00000043 */  sra       $zero, $zero, 1
/* 4FC0E0 8021C500 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC0E4 8021C504 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FC0E8 8021C508 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC0EC 8021C50C FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4FC0F0 8021C510 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 4FC0F4 8021C514 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC0F8 8021C518 00000043 */  sra       $zero, $zero, 1
/* 4FC0FC 8021C51C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC100 8021C520 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FC104 8021C524 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC108 8021C528 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC10C 8021C52C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC110 8021C530 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC114 8021C534 00000043 */  sra       $zero, $zero, 1
/* 4FC118 8021C538 00000004 */  sllv      $zero, $zero, $zero
/* 4FC11C 8021C53C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FC120 8021C540 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC124 8021C544 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC128 8021C548 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FC12C 8021C54C 00000043 */  sra       $zero, $zero, 1
/* 4FC130 8021C550 00000009 */  jr        $zero
/* 4FC134 8021C554 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC138 8021C558 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC13C 8021C55C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC140 8021C560 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC144 8021C564 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC148 8021C568 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC14C 8021C56C 00000000 */  nop       
/* 4FC150 8021C570 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC154 8021C574 00000000 */  nop       
/* 4FC158 8021C578 00000043 */  sra       $zero, $zero, 1
/* 4FC15C 8021C57C 00000004 */  sllv      $zero, $zero, $zero
/* 4FC160 8021C580 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC164 8021C584 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC168 8021C588 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC16C 8021C58C 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FC170 8021C590 00000043 */  sra       $zero, $zero, 1
/* 4FC174 8021C594 00000004 */  sllv      $zero, $zero, $zero
/* 4FC178 8021C598 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FC17C 8021C59C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC180 8021C5A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC184 8021C5A4 000000B4 */  teq       $zero, $zero, 2
/* 4FC188 8021C5A8 00000043 */  sra       $zero, $zero, 1
/* 4FC18C 8021C5AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC190 8021C5B0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FC194 8021C5B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC198 8021C5B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC19C 8021C5BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC1A0 8021C5C0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC1A4 8021C5C4 00000027 */  not       $zero, $zero
/* 4FC1A8 8021C5C8 00000002 */  srl       $zero, $zero, 0
/* 4FC1AC 8021C5CC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC1B0 8021C5D0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC1B4 8021C5D4 00000027 */  not       $zero, $zero
/* 4FC1B8 8021C5D8 00000002 */  srl       $zero, $zero, 0
/* 4FC1BC 8021C5DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC1C0 8021C5E0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC1C4 8021C5E4 00000043 */  sra       $zero, $zero, 1
/* 4FC1C8 8021C5E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC1CC 8021C5EC 8026EE88 */  lb        $a2, -0x1178($at)
/* 4FC1D0 8021C5F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC1D4 8021C5F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC1D8 8021C5F8 00000000 */  nop       
/* 4FC1DC 8021C5FC 00000002 */  srl       $zero, $zero, 0
/* 4FC1E0 8021C600 00000043 */  sra       $zero, $zero, 1
/* 4FC1E4 8021C604 00000009 */  jr        $zero
/* 4FC1E8 8021C608 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC1EC 8021C60C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC1F0 8021C610 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC1F4 8021C614 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC1F8 8021C618 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC1FC 8021C61C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC200 8021C620 00000000 */  nop       
/* 4FC204 8021C624 0000000A */  movz      $zero, $zero, $zero
/* 4FC208 8021C628 00000000 */  nop       
/* 4FC20C 8021C62C 00000043 */  sra       $zero, $zero, 1
/* 4FC210 8021C630 00000004 */  sllv      $zero, $zero, $zero
/* 4FC214 8021C634 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4FC218 8021C638 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC21C 8021C63C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC220 8021C640 00000000 */  nop       
/* 4FC224 8021C644 00000043 */  sra       $zero, $zero, 1
/* 4FC228 8021C648 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC22C 8021C64C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FC230 8021C650 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC234 8021C654 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC238 8021C658 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC23C 8021C65C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC240 8021C660 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FC244 8021C664 00000000 */  nop       
/* 4FC248 8021C668 00000008 */  jr        $zero
/* 4FC24C 8021C66C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC250 8021C670 0000000B */  movn      $zero, $zero, $zero
/* 4FC254 8021C674 00000056 */  drotrv    $zero, $zero, $zero
/* 4FC258 8021C678 00000000 */  nop       
/* 4FC25C 8021C67C 00000043 */  sra       $zero, $zero, 1
/* 4FC260 8021C680 00000004 */  sllv      $zero, $zero, $zero
/* 4FC264 8021C684 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FC268 8021C688 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC26C 8021C68C 00000006 */  srlv      $zero, $zero, $zero
/* 4FC270 8021C690 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FC274 8021C694 00000043 */  sra       $zero, $zero, 1
/* 4FC278 8021C698 00000004 */  sllv      $zero, $zero, $zero
/* 4FC27C 8021C69C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC280 8021C6A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC284 8021C6A4 00000006 */  srlv      $zero, $zero, $zero
/* 4FC288 8021C6A8 004B0004 */  sllv      $zero, $t3, $v0
/* 4FC28C 8021C6AC 00000043 */  sra       $zero, $zero, 1
/* 4FC290 8021C6B0 00000002 */  srl       $zero, $zero, 0
/* 4FC294 8021C6B4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC298 8021C6B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC29C 8021C6BC 00000043 */  sra       $zero, $zero, 1
/* 4FC2A0 8021C6C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC2A4 8021C6C4 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FC2A8 8021C6C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC2AC 8021C6CC FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 4FC2B0 8021C6D0 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 4FC2B4 8021C6D4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC2B8 8021C6D8 00000043 */  sra       $zero, $zero, 1
/* 4FC2BC 8021C6DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC2C0 8021C6E0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FC2C4 8021C6E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC2C8 8021C6E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC2CC 8021C6EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC2D0 8021C6F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC2D4 8021C6F4 00000043 */  sra       $zero, $zero, 1
/* 4FC2D8 8021C6F8 00000004 */  sllv      $zero, $zero, $zero
/* 4FC2DC 8021C6FC 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FC2E0 8021C700 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC2E4 8021C704 00000006 */  srlv      $zero, $zero, $zero
/* 4FC2E8 8021C708 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FC2EC 8021C70C 00000043 */  sra       $zero, $zero, 1
/* 4FC2F0 8021C710 00000009 */  jr        $zero
/* 4FC2F4 8021C714 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC2F8 8021C718 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC2FC 8021C71C 00000006 */  srlv      $zero, $zero, $zero
/* 4FC300 8021C720 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC304 8021C724 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC308 8021C728 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC30C 8021C72C 00000000 */  nop       
/* 4FC310 8021C730 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC314 8021C734 00000000 */  nop       
/* 4FC318 8021C738 00000043 */  sra       $zero, $zero, 1
/* 4FC31C 8021C73C 00000004 */  sllv      $zero, $zero, $zero
/* 4FC320 8021C740 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC324 8021C744 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC328 8021C748 00000006 */  srlv      $zero, $zero, $zero
/* 4FC32C 8021C74C 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FC330 8021C750 00000043 */  sra       $zero, $zero, 1
/* 4FC334 8021C754 00000004 */  sllv      $zero, $zero, $zero
/* 4FC338 8021C758 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FC33C 8021C75C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC340 8021C760 00000006 */  srlv      $zero, $zero, $zero
/* 4FC344 8021C764 000000B4 */  teq       $zero, $zero, 2
/* 4FC348 8021C768 00000043 */  sra       $zero, $zero, 1
/* 4FC34C 8021C76C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC350 8021C770 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FC354 8021C774 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC358 8021C778 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC35C 8021C77C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC360 8021C780 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC364 8021C784 00000027 */  not       $zero, $zero
/* 4FC368 8021C788 00000002 */  srl       $zero, $zero, 0
/* 4FC36C 8021C78C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC370 8021C790 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC374 8021C794 00000027 */  not       $zero, $zero
/* 4FC378 8021C798 00000002 */  srl       $zero, $zero, 0
/* 4FC37C 8021C79C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC380 8021C7A0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC384 8021C7A4 00000043 */  sra       $zero, $zero, 1
/* 4FC388 8021C7A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC38C 8021C7AC 8026EE88 */  lb        $a2, -0x1178($at)
/* 4FC390 8021C7B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC394 8021C7B4 00000006 */  srlv      $zero, $zero, $zero
/* 4FC398 8021C7B8 00000000 */  nop       
/* 4FC39C 8021C7BC 00000002 */  srl       $zero, $zero, 0
/* 4FC3A0 8021C7C0 00000043 */  sra       $zero, $zero, 1
/* 4FC3A4 8021C7C4 00000009 */  jr        $zero
/* 4FC3A8 8021C7C8 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC3AC 8021C7CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC3B0 8021C7D0 00000006 */  srlv      $zero, $zero, $zero
/* 4FC3B4 8021C7D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC3B8 8021C7D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC3BC 8021C7DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC3C0 8021C7E0 00000000 */  nop       
/* 4FC3C4 8021C7E4 0000000A */  movz      $zero, $zero, $zero
/* 4FC3C8 8021C7E8 00000000 */  nop       
/* 4FC3CC 8021C7EC 00000043 */  sra       $zero, $zero, 1
/* 4FC3D0 8021C7F0 00000004 */  sllv      $zero, $zero, $zero
/* 4FC3D4 8021C7F4 8026EF4C */  lb        $a2, -0x10b4($at)
/* 4FC3D8 8021C7F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC3DC 8021C7FC 00000006 */  srlv      $zero, $zero, $zero
/* 4FC3E0 8021C800 00000000 */  nop       
/* 4FC3E4 8021C804 00000043 */  sra       $zero, $zero, 1
/* 4FC3E8 8021C808 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC3EC 8021C80C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FC3F0 8021C810 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC3F4 8021C814 00000006 */  srlv      $zero, $zero, $zero
/* 4FC3F8 8021C818 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC3FC 8021C81C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC400 8021C820 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FC404 8021C824 00000000 */  nop       
/* 4FC408 8021C828 00000008 */  jr        $zero
/* 4FC40C 8021C82C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC410 8021C830 0000000B */  movn      $zero, $zero, $zero
/* 4FC414 8021C834 0000000A */  movz      $zero, $zero, $zero
/* 4FC418 8021C838 00000002 */  srl       $zero, $zero, 0
/* 4FC41C 8021C83C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FC420 8021C840 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC424 8021C844 00000043 */  sra       $zero, $zero, 1
/* 4FC428 8021C848 00000007 */  srav      $zero, $zero, $zero
/* 4FC42C 8021C84C 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4FC430 8021C850 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC434 8021C854 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC438 8021C858 80000000 */  lb        $zero, ($zero)
/* 4FC43C 8021C85C 00000000 */  nop       
/* 4FC440 8021C860 00000000 */  nop       
/* 4FC444 8021C864 00000000 */  nop       
/* 4FC448 8021C868 00000013 */  mtlo      $zero
/* 4FC44C 8021C86C 00000000 */  nop       
/* 4FC450 8021C870 00000008 */  jr        $zero
/* 4FC454 8021C874 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC458 8021C878 0000001E */  ddiv      $zero, $zero, $zero
/* 4FC45C 8021C87C 00000043 */  sra       $zero, $zero, 1
/* 4FC460 8021C880 00000002 */  srl       $zero, $zero, 0
/* 4FC464 8021C884 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FC468 8021C888 00000002 */  srl       $zero, $zero, 0
/* 4FC46C 8021C88C 00000008 */  jr        $zero
/* 4FC470 8021C890 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC474 8021C894 0000001E */  ddiv      $zero, $zero, $zero
/* 4FC478 8021C898 00000043 */  sra       $zero, $zero, 1
/* 4FC47C 8021C89C 00000002 */  srl       $zero, $zero, 0
/* 4FC480 8021C8A0 802D62B8 */  lb        $t5, 0x62b8($at)
/* 4FC484 8021C8A4 00000358 */  .byte     0x00, 0x00, 0x03, 0x58
/* 4FC488 8021C8A8 00000043 */  sra       $zero, $zero, 1
/* 4FC48C 8021C8AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC490 8021C8B0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4FC494 8021C8B4 00000043 */  sra       $zero, $zero, 1
/* 4FC498 8021C8B8 00000003 */  sra       $zero, $zero, 0
/* 4FC49C 8021C8BC 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FC4A0 8021C8C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC4A4 8021C8C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC4A8 8021C8C8 00000043 */  sra       $zero, $zero, 1
/* 4FC4AC 8021C8CC 00000003 */  sra       $zero, $zero, 0
/* 4FC4B0 8021C8D0 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FC4B4 8021C8D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC4B8 8021C8D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC4BC 8021C8DC 00000002 */  srl       $zero, $zero, 0
/* 4FC4C0 8021C8E0 00000000 */  nop       
/* 4FC4C4 8021C8E4 00000020 */  add       $zero, $zero, $zero
/* 4FC4C8 8021C8E8 00000000 */  nop       
/* 4FC4CC 8021C8EC 00000023 */  negu      $zero, $zero
/* 4FC4D0 8021C8F0 00000000 */  nop       
/* 4FC4D4 8021C8F4 00000056 */  drotrv    $zero, $zero, $zero
/* 4FC4D8 8021C8F8 00000000 */  nop       
/* 4FC4DC 8021C8FC 00000043 */  sra       $zero, $zero, 1
/* 4FC4E0 8021C900 00000004 */  sllv      $zero, $zero, $zero
/* 4FC4E4 8021C904 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FC4E8 8021C908 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC4EC 8021C90C 00000002 */  srl       $zero, $zero, 0
/* 4FC4F0 8021C910 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FC4F4 8021C914 00000043 */  sra       $zero, $zero, 1
/* 4FC4F8 8021C918 00000004 */  sllv      $zero, $zero, $zero
/* 4FC4FC 8021C91C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC500 8021C920 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC504 8021C924 00000002 */  srl       $zero, $zero, 0
/* 4FC508 8021C928 004B0004 */  sllv      $zero, $t3, $v0
/* 4FC50C 8021C92C 00000043 */  sra       $zero, $zero, 1
/* 4FC510 8021C930 00000002 */  srl       $zero, $zero, 0
/* 4FC514 8021C934 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC518 8021C938 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC51C 8021C93C 00000043 */  sra       $zero, $zero, 1
/* 4FC520 8021C940 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC524 8021C944 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FC528 8021C948 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC52C 8021C94C FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC530 8021C950 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC534 8021C954 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC538 8021C958 00000043 */  sra       $zero, $zero, 1
/* 4FC53C 8021C95C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC540 8021C960 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FC544 8021C964 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC548 8021C968 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC54C 8021C96C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC550 8021C970 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC554 8021C974 00000043 */  sra       $zero, $zero, 1
/* 4FC558 8021C978 00000004 */  sllv      $zero, $zero, $zero
/* 4FC55C 8021C97C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FC560 8021C980 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC564 8021C984 00000002 */  srl       $zero, $zero, 0
/* 4FC568 8021C988 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FC56C 8021C98C 00000043 */  sra       $zero, $zero, 1
/* 4FC570 8021C990 00000009 */  jr        $zero
/* 4FC574 8021C994 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC578 8021C998 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC57C 8021C99C 00000002 */  srl       $zero, $zero, 0
/* 4FC580 8021C9A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC584 8021C9A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC588 8021C9A8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC58C 8021C9AC 00000000 */  nop       
/* 4FC590 8021C9B0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC594 8021C9B4 00000000 */  nop       
/* 4FC598 8021C9B8 00000008 */  jr        $zero
/* 4FC59C 8021C9BC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC5A0 8021C9C0 00000002 */  srl       $zero, $zero, 0
/* 4FC5A4 8021C9C4 00000043 */  sra       $zero, $zero, 1
/* 4FC5A8 8021C9C8 00000002 */  srl       $zero, $zero, 0
/* 4FC5AC 8021C9CC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC5B0 8021C9D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC5B4 8021C9D4 00000043 */  sra       $zero, $zero, 1
/* 4FC5B8 8021C9D8 00000008 */  jr        $zero
/* 4FC5BC 8021C9DC 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FC5C0 8021C9E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC5C4 8021C9E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC5C8 8021C9E8 10000000 */  b         .L8021C9EC
.L8021C9EC:
/* 4FC5CC 8021C9EC 00000000 */   nop      
/* 4FC5D0 8021C9F0 00000000 */  nop       
/* 4FC5D4 8021C9F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC5D8 8021C9F8 00000010 */  mfhi      $zero
/* 4FC5DC 8021C9FC 00000043 */  sra       $zero, $zero, 1
/* 4FC5E0 8021CA00 00000004 */  sllv      $zero, $zero, $zero
/* 4FC5E4 8021CA04 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC5E8 8021CA08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC5EC 8021CA0C 00000002 */  srl       $zero, $zero, 0
/* 4FC5F0 8021CA10 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FC5F4 8021CA14 00000043 */  sra       $zero, $zero, 1
/* 4FC5F8 8021CA18 00000004 */  sllv      $zero, $zero, $zero
/* 4FC5FC 8021CA1C 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FC600 8021CA20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC604 8021CA24 00000002 */  srl       $zero, $zero, 0
/* 4FC608 8021CA28 000000B4 */  teq       $zero, $zero, 2
/* 4FC60C 8021CA2C 00000043 */  sra       $zero, $zero, 1
/* 4FC610 8021CA30 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC614 8021CA34 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FC618 8021CA38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC61C 8021CA3C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC620 8021CA40 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC624 8021CA44 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC628 8021CA48 00000027 */  not       $zero, $zero
/* 4FC62C 8021CA4C 00000002 */  srl       $zero, $zero, 0
/* 4FC630 8021CA50 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC634 8021CA54 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC638 8021CA58 00000027 */  not       $zero, $zero
/* 4FC63C 8021CA5C 00000002 */  srl       $zero, $zero, 0
/* 4FC640 8021CA60 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC644 8021CA64 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC648 8021CA68 00000043 */  sra       $zero, $zero, 1
/* 4FC64C 8021CA6C 00000009 */  jr        $zero
/* 4FC650 8021CA70 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC654 8021CA74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC658 8021CA78 00000002 */  srl       $zero, $zero, 0
/* 4FC65C 8021CA7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC660 8021CA80 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC664 8021CA84 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC668 8021CA88 00000000 */  nop       
/* 4FC66C 8021CA8C 0000000A */  movz      $zero, $zero, $zero
/* 4FC670 8021CA90 00000000 */  nop       
/* 4FC674 8021CA94 00000043 */  sra       $zero, $zero, 1
/* 4FC678 8021CA98 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC67C 8021CA9C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FC680 8021CAA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC684 8021CAA4 00000002 */  srl       $zero, $zero, 0
/* 4FC688 8021CAA8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC68C 8021CAAC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC690 8021CAB0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FC694 8021CAB4 00000000 */  nop       
/* 4FC698 8021CAB8 00000008 */  jr        $zero
/* 4FC69C 8021CABC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC6A0 8021CAC0 0000000B */  movn      $zero, $zero, $zero
/* 4FC6A4 8021CAC4 00000056 */  drotrv    $zero, $zero, $zero
/* 4FC6A8 8021CAC8 00000000 */  nop       
/* 4FC6AC 8021CACC 00000043 */  sra       $zero, $zero, 1
/* 4FC6B0 8021CAD0 00000004 */  sllv      $zero, $zero, $zero
/* 4FC6B4 8021CAD4 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FC6B8 8021CAD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC6BC 8021CADC 00000003 */  sra       $zero, $zero, 0
/* 4FC6C0 8021CAE0 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FC6C4 8021CAE4 00000043 */  sra       $zero, $zero, 1
/* 4FC6C8 8021CAE8 00000004 */  sllv      $zero, $zero, $zero
/* 4FC6CC 8021CAEC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC6D0 8021CAF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC6D4 8021CAF4 00000003 */  sra       $zero, $zero, 0
/* 4FC6D8 8021CAF8 004B0004 */  sllv      $zero, $t3, $v0
/* 4FC6DC 8021CAFC 00000043 */  sra       $zero, $zero, 1
/* 4FC6E0 8021CB00 00000002 */  srl       $zero, $zero, 0
/* 4FC6E4 8021CB04 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC6E8 8021CB08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC6EC 8021CB0C 00000043 */  sra       $zero, $zero, 1
/* 4FC6F0 8021CB10 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC6F4 8021CB14 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FC6F8 8021CB18 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC6FC 8021CB1C FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC700 8021CB20 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC704 8021CB24 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC708 8021CB28 00000043 */  sra       $zero, $zero, 1
/* 4FC70C 8021CB2C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC710 8021CB30 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FC714 8021CB34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC718 8021CB38 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC71C 8021CB3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC720 8021CB40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC724 8021CB44 00000043 */  sra       $zero, $zero, 1
/* 4FC728 8021CB48 00000004 */  sllv      $zero, $zero, $zero
/* 4FC72C 8021CB4C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FC730 8021CB50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC734 8021CB54 00000003 */  sra       $zero, $zero, 0
/* 4FC738 8021CB58 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FC73C 8021CB5C 00000043 */  sra       $zero, $zero, 1
/* 4FC740 8021CB60 00000009 */  jr        $zero
/* 4FC744 8021CB64 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC748 8021CB68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC74C 8021CB6C 00000003 */  sra       $zero, $zero, 0
/* 4FC750 8021CB70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC754 8021CB74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC758 8021CB78 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC75C 8021CB7C 00000000 */  nop       
/* 4FC760 8021CB80 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC764 8021CB84 00000000 */  nop       
/* 4FC768 8021CB88 00000008 */  jr        $zero
/* 4FC76C 8021CB8C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC770 8021CB90 00000002 */  srl       $zero, $zero, 0
/* 4FC774 8021CB94 00000043 */  sra       $zero, $zero, 1
/* 4FC778 8021CB98 00000002 */  srl       $zero, $zero, 0
/* 4FC77C 8021CB9C 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC780 8021CBA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC784 8021CBA4 00000043 */  sra       $zero, $zero, 1
/* 4FC788 8021CBA8 00000008 */  jr        $zero
/* 4FC78C 8021CBAC 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FC790 8021CBB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC794 8021CBB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC798 8021CBB8 10000000 */  b         .L8021CBBC
.L8021CBBC:
/* 4FC79C 8021CBBC 00000000 */   nop      
/* 4FC7A0 8021CBC0 00000000 */  nop       
/* 4FC7A4 8021CBC4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC7A8 8021CBC8 00000040 */  ssnop     
/* 4FC7AC 8021CBCC 00000043 */  sra       $zero, $zero, 1
/* 4FC7B0 8021CBD0 00000004 */  sllv      $zero, $zero, $zero
/* 4FC7B4 8021CBD4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC7B8 8021CBD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC7BC 8021CBDC 00000003 */  sra       $zero, $zero, 0
/* 4FC7C0 8021CBE0 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FC7C4 8021CBE4 00000043 */  sra       $zero, $zero, 1
/* 4FC7C8 8021CBE8 00000004 */  sllv      $zero, $zero, $zero
/* 4FC7CC 8021CBEC 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FC7D0 8021CBF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC7D4 8021CBF4 00000003 */  sra       $zero, $zero, 0
/* 4FC7D8 8021CBF8 000000B4 */  teq       $zero, $zero, 2
/* 4FC7DC 8021CBFC 00000043 */  sra       $zero, $zero, 1
/* 4FC7E0 8021CC00 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC7E4 8021CC04 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FC7E8 8021CC08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC7EC 8021CC0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC7F0 8021CC10 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC7F4 8021CC14 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC7F8 8021CC18 00000027 */  not       $zero, $zero
/* 4FC7FC 8021CC1C 00000002 */  srl       $zero, $zero, 0
/* 4FC800 8021CC20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC804 8021CC24 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC808 8021CC28 00000027 */  not       $zero, $zero
/* 4FC80C 8021CC2C 00000002 */  srl       $zero, $zero, 0
/* 4FC810 8021CC30 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC814 8021CC34 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC818 8021CC38 00000043 */  sra       $zero, $zero, 1
/* 4FC81C 8021CC3C 00000009 */  jr        $zero
/* 4FC820 8021CC40 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC824 8021CC44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC828 8021CC48 00000003 */  sra       $zero, $zero, 0
/* 4FC82C 8021CC4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC830 8021CC50 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC834 8021CC54 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC838 8021CC58 00000000 */  nop       
/* 4FC83C 8021CC5C 0000000A */  movz      $zero, $zero, $zero
/* 4FC840 8021CC60 00000000 */  nop       
/* 4FC844 8021CC64 00000043 */  sra       $zero, $zero, 1
/* 4FC848 8021CC68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC84C 8021CC6C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FC850 8021CC70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC854 8021CC74 00000003 */  sra       $zero, $zero, 0
/* 4FC858 8021CC78 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC85C 8021CC7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC860 8021CC80 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FC864 8021CC84 00000000 */  nop       
/* 4FC868 8021CC88 00000008 */  jr        $zero
/* 4FC86C 8021CC8C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC870 8021CC90 0000000B */  movn      $zero, $zero, $zero
/* 4FC874 8021CC94 00000056 */  drotrv    $zero, $zero, $zero
/* 4FC878 8021CC98 00000000 */  nop       
/* 4FC87C 8021CC9C 00000043 */  sra       $zero, $zero, 1
/* 4FC880 8021CCA0 00000004 */  sllv      $zero, $zero, $zero
/* 4FC884 8021CCA4 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FC888 8021CCA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC88C 8021CCAC 00000004 */  sllv      $zero, $zero, $zero
/* 4FC890 8021CCB0 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FC894 8021CCB4 00000043 */  sra       $zero, $zero, 1
/* 4FC898 8021CCB8 00000004 */  sllv      $zero, $zero, $zero
/* 4FC89C 8021CCBC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC8A0 8021CCC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC8A4 8021CCC4 00000004 */  sllv      $zero, $zero, $zero
/* 4FC8A8 8021CCC8 004B0004 */  sllv      $zero, $t3, $v0
/* 4FC8AC 8021CCCC 00000043 */  sra       $zero, $zero, 1
/* 4FC8B0 8021CCD0 00000002 */  srl       $zero, $zero, 0
/* 4FC8B4 8021CCD4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC8B8 8021CCD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC8BC 8021CCDC 00000043 */  sra       $zero, $zero, 1
/* 4FC8C0 8021CCE0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC8C4 8021CCE4 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FC8C8 8021CCE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC8CC 8021CCEC FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC8D0 8021CCF0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC8D4 8021CCF4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC8D8 8021CCF8 00000043 */  sra       $zero, $zero, 1
/* 4FC8DC 8021CCFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC8E0 8021CD00 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FC8E4 8021CD04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC8E8 8021CD08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC8EC 8021CD0C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC8F0 8021CD10 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC8F4 8021CD14 00000043 */  sra       $zero, $zero, 1
/* 4FC8F8 8021CD18 00000004 */  sllv      $zero, $zero, $zero
/* 4FC8FC 8021CD1C 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FC900 8021CD20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC904 8021CD24 00000004 */  sllv      $zero, $zero, $zero
/* 4FC908 8021CD28 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FC90C 8021CD2C 00000043 */  sra       $zero, $zero, 1
/* 4FC910 8021CD30 00000009 */  jr        $zero
/* 4FC914 8021CD34 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC918 8021CD38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC91C 8021CD3C 00000004 */  sllv      $zero, $zero, $zero
/* 4FC920 8021CD40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC924 8021CD44 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC928 8021CD48 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC92C 8021CD4C 00000000 */  nop       
/* 4FC930 8021CD50 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FC934 8021CD54 00000000 */  nop       
/* 4FC938 8021CD58 00000008 */  jr        $zero
/* 4FC93C 8021CD5C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FC940 8021CD60 00000002 */  srl       $zero, $zero, 0
/* 4FC944 8021CD64 00000043 */  sra       $zero, $zero, 1
/* 4FC948 8021CD68 00000002 */  srl       $zero, $zero, 0
/* 4FC94C 8021CD6C 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FC950 8021CD70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC954 8021CD74 00000043 */  sra       $zero, $zero, 1
/* 4FC958 8021CD78 00000008 */  jr        $zero
/* 4FC95C 8021CD7C 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FC960 8021CD80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC964 8021CD84 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC968 8021CD88 10000000 */  b         .L8021CD8C
.L8021CD8C:
/* 4FC96C 8021CD8C 00000000 */   nop      
/* 4FC970 8021CD90 00000000 */  nop       
/* 4FC974 8021CD94 00000001 */  movf      $zero, $zero, $fcc0
/* 4FC978 8021CD98 00000040 */  ssnop     
/* 4FC97C 8021CD9C 00000043 */  sra       $zero, $zero, 1
/* 4FC980 8021CDA0 00000004 */  sllv      $zero, $zero, $zero
/* 4FC984 8021CDA4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FC988 8021CDA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC98C 8021CDAC 00000004 */  sllv      $zero, $zero, $zero
/* 4FC990 8021CDB0 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FC994 8021CDB4 00000043 */  sra       $zero, $zero, 1
/* 4FC998 8021CDB8 00000004 */  sllv      $zero, $zero, $zero
/* 4FC99C 8021CDBC 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FC9A0 8021CDC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC9A4 8021CDC4 00000004 */  sllv      $zero, $zero, $zero
/* 4FC9A8 8021CDC8 000000B4 */  teq       $zero, $zero, 2
/* 4FC9AC 8021CDCC 00000043 */  sra       $zero, $zero, 1
/* 4FC9B0 8021CDD0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FC9B4 8021CDD4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FC9B8 8021CDD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC9BC 8021CDDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FC9C0 8021CDE0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC9C4 8021CDE4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC9C8 8021CDE8 00000027 */  not       $zero, $zero
/* 4FC9CC 8021CDEC 00000002 */  srl       $zero, $zero, 0
/* 4FC9D0 8021CDF0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FC9D4 8021CDF4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC9D8 8021CDF8 00000027 */  not       $zero, $zero
/* 4FC9DC 8021CDFC 00000002 */  srl       $zero, $zero, 0
/* 4FC9E0 8021CE00 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FC9E4 8021CE04 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FC9E8 8021CE08 00000043 */  sra       $zero, $zero, 1
/* 4FC9EC 8021CE0C 00000009 */  jr        $zero
/* 4FC9F0 8021CE10 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FC9F4 8021CE14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FC9F8 8021CE18 00000004 */  sllv      $zero, $zero, $zero
/* 4FC9FC 8021CE1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCA00 8021CE20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCA04 8021CE24 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCA08 8021CE28 00000000 */  nop       
/* 4FCA0C 8021CE2C 0000000A */  movz      $zero, $zero, $zero
/* 4FCA10 8021CE30 00000000 */  nop       
/* 4FCA14 8021CE34 00000043 */  sra       $zero, $zero, 1
/* 4FCA18 8021CE38 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCA1C 8021CE3C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FCA20 8021CE40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCA24 8021CE44 00000004 */  sllv      $zero, $zero, $zero
/* 4FCA28 8021CE48 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCA2C 8021CE4C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCA30 8021CE50 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FCA34 8021CE54 00000000 */  nop       
/* 4FCA38 8021CE58 00000008 */  jr        $zero
/* 4FCA3C 8021CE5C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FCA40 8021CE60 0000000B */  movn      $zero, $zero, $zero
/* 4FCA44 8021CE64 00000056 */  drotrv    $zero, $zero, $zero
/* 4FCA48 8021CE68 00000000 */  nop       
/* 4FCA4C 8021CE6C 00000043 */  sra       $zero, $zero, 1
/* 4FCA50 8021CE70 00000004 */  sllv      $zero, $zero, $zero
/* 4FCA54 8021CE74 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FCA58 8021CE78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCA5C 8021CE7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCA60 8021CE80 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FCA64 8021CE84 00000043 */  sra       $zero, $zero, 1
/* 4FCA68 8021CE88 00000004 */  sllv      $zero, $zero, $zero
/* 4FCA6C 8021CE8C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FCA70 8021CE90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCA74 8021CE94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCA78 8021CE98 004B0004 */  sllv      $zero, $t3, $v0
/* 4FCA7C 8021CE9C 00000043 */  sra       $zero, $zero, 1
/* 4FCA80 8021CEA0 00000002 */  srl       $zero, $zero, 0
/* 4FCA84 8021CEA4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FCA88 8021CEA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCA8C 8021CEAC 00000043 */  sra       $zero, $zero, 1
/* 4FCA90 8021CEB0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCA94 8021CEB4 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FCA98 8021CEB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCA9C 8021CEBC FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FCAA0 8021CEC0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FCAA4 8021CEC4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCAA8 8021CEC8 00000043 */  sra       $zero, $zero, 1
/* 4FCAAC 8021CECC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCAB0 8021CED0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FCAB4 8021CED4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCAB8 8021CED8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCABC 8021CEDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCAC0 8021CEE0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCAC4 8021CEE4 00000043 */  sra       $zero, $zero, 1
/* 4FCAC8 8021CEE8 00000004 */  sllv      $zero, $zero, $zero
/* 4FCACC 8021CEEC 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FCAD0 8021CEF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCAD4 8021CEF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCAD8 8021CEF8 F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FCADC 8021CEFC 00000043 */  sra       $zero, $zero, 1
/* 4FCAE0 8021CF00 00000009 */  jr        $zero
/* 4FCAE4 8021CF04 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FCAE8 8021CF08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCAEC 8021CF0C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCAF0 8021CF10 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCAF4 8021CF14 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCAF8 8021CF18 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCAFC 8021CF1C 00000000 */  nop       
/* 4FCB00 8021CF20 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FCB04 8021CF24 00000000 */  nop       
/* 4FCB08 8021CF28 00000008 */  jr        $zero
/* 4FCB0C 8021CF2C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FCB10 8021CF30 00000002 */  srl       $zero, $zero, 0
/* 4FCB14 8021CF34 00000043 */  sra       $zero, $zero, 1
/* 4FCB18 8021CF38 00000002 */  srl       $zero, $zero, 0
/* 4FCB1C 8021CF3C 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FCB20 8021CF40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCB24 8021CF44 00000043 */  sra       $zero, $zero, 1
/* 4FCB28 8021CF48 00000008 */  jr        $zero
/* 4FCB2C 8021CF4C 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FCB30 8021CF50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCB34 8021CF54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCB38 8021CF58 10000000 */  b         .L8021CF5C
.L8021CF5C:
/* 4FCB3C 8021CF5C 00000000 */   nop      
/* 4FCB40 8021CF60 00000000 */  nop       
/* 4FCB44 8021CF64 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCB48 8021CF68 00000040 */  ssnop     
/* 4FCB4C 8021CF6C 00000043 */  sra       $zero, $zero, 1
/* 4FCB50 8021CF70 00000004 */  sllv      $zero, $zero, $zero
/* 4FCB54 8021CF74 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FCB58 8021CF78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCB5C 8021CF7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCB60 8021CF80 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FCB64 8021CF84 00000043 */  sra       $zero, $zero, 1
/* 4FCB68 8021CF88 00000004 */  sllv      $zero, $zero, $zero
/* 4FCB6C 8021CF8C 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FCB70 8021CF90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCB74 8021CF94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCB78 8021CF98 000000B4 */  teq       $zero, $zero, 2
/* 4FCB7C 8021CF9C 00000043 */  sra       $zero, $zero, 1
/* 4FCB80 8021CFA0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCB84 8021CFA4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FCB88 8021CFA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCB8C 8021CFAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCB90 8021CFB0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCB94 8021CFB4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCB98 8021CFB8 00000027 */  not       $zero, $zero
/* 4FCB9C 8021CFBC 00000002 */  srl       $zero, $zero, 0
/* 4FCBA0 8021CFC0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCBA4 8021CFC4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FCBA8 8021CFC8 00000027 */  not       $zero, $zero
/* 4FCBAC 8021CFCC 00000002 */  srl       $zero, $zero, 0
/* 4FCBB0 8021CFD0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCBB4 8021CFD4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FCBB8 8021CFD8 00000043 */  sra       $zero, $zero, 1
/* 4FCBBC 8021CFDC 00000009 */  jr        $zero
/* 4FCBC0 8021CFE0 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FCBC4 8021CFE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCBC8 8021CFE8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCBCC 8021CFEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCBD0 8021CFF0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCBD4 8021CFF4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCBD8 8021CFF8 00000000 */  nop       
/* 4FCBDC 8021CFFC 0000000A */  movz      $zero, $zero, $zero
/* 4FCBE0 8021D000 00000000 */  nop       
/* 4FCBE4 8021D004 00000043 */  sra       $zero, $zero, 1
/* 4FCBE8 8021D008 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCBEC 8021D00C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FCBF0 8021D010 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCBF4 8021D014 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCBF8 8021D018 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCBFC 8021D01C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCC00 8021D020 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FCC04 8021D024 00000000 */  nop       
/* 4FCC08 8021D028 00000008 */  jr        $zero
/* 4FCC0C 8021D02C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FCC10 8021D030 0000000B */  movn      $zero, $zero, $zero
/* 4FCC14 8021D034 00000008 */  jr        $zero
/* 4FCC18 8021D038 00000001 */   movf     $zero, $zero, $fcc0
/* 4FCC1C 8021D03C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCC20 8021D040 00000043 */  sra       $zero, $zero, 1
/* 4FCC24 8021D044 00000004 */  sllv      $zero, $zero, $zero
/* 4FCC28 8021D048 802538D0 */  lb        $a1, 0x38d0($at)
/* 4FCC2C 8021D04C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCC30 8021D050 00000006 */  srlv      $zero, $zero, $zero
/* 4FCC34 8021D054 000020CB */  .byte     0x00, 0x00, 0x20, 0xcb
/* 4FCC38 8021D058 00000043 */  sra       $zero, $zero, 1
/* 4FCC3C 8021D05C 00000004 */  sllv      $zero, $zero, $zero
/* 4FCC40 8021D060 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FCC44 8021D064 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCC48 8021D068 00000006 */  srlv      $zero, $zero, $zero
/* 4FCC4C 8021D06C 004B0004 */  sllv      $zero, $t3, $v0
/* 4FCC50 8021D070 00000043 */  sra       $zero, $zero, 1
/* 4FCC54 8021D074 00000002 */  srl       $zero, $zero, 0
/* 4FCC58 8021D078 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FCC5C 8021D07C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCC60 8021D080 00000043 */  sra       $zero, $zero, 1
/* 4FCC64 8021D084 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCC68 8021D088 8026A748 */  lb        $a2, -0x58b8($at)
/* 4FCC6C 8021D08C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCC70 8021D090 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FCC74 8021D094 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FCC78 8021D098 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCC7C 8021D09C 00000043 */  sra       $zero, $zero, 1
/* 4FCC80 8021D0A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCC84 8021D0A4 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FCC88 8021D0A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCC8C 8021D0AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCC90 8021D0B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCC94 8021D0B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCC98 8021D0B8 00000043 */  sra       $zero, $zero, 1
/* 4FCC9C 8021D0BC 00000004 */  sllv      $zero, $zero, $zero
/* 4FCCA0 8021D0C0 8026B7EC */  lb        $a2, -0x4814($at)
/* 4FCCA4 8021D0C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCCA8 8021D0C8 00000006 */  srlv      $zero, $zero, $zero
/* 4FCCAC 8021D0CC F24A8680 */  scd       $t2, -0x7980($s2)
/* 4FCCB0 8021D0D0 00000043 */  sra       $zero, $zero, 1
/* 4FCCB4 8021D0D4 00000009 */  jr        $zero
/* 4FCCB8 8021D0D8 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FCCBC 8021D0DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCCC0 8021D0E0 00000006 */  srlv      $zero, $zero, $zero
/* 4FCCC4 8021D0E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCCC8 8021D0E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCCCC 8021D0EC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCCD0 8021D0F0 00000000 */  nop       
/* 4FCCD4 8021D0F4 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 4FCCD8 8021D0F8 00000000 */  nop       
/* 4FCCDC 8021D0FC 00000008 */  jr        $zero
/* 4FCCE0 8021D100 00000001 */   movf     $zero, $zero, $fcc0
/* 4FCCE4 8021D104 00000002 */  srl       $zero, $zero, 0
/* 4FCCE8 8021D108 00000043 */  sra       $zero, $zero, 1
/* 4FCCEC 8021D10C 00000002 */  srl       $zero, $zero, 0
/* 4FCCF0 8021D110 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FCCF4 8021D114 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCCF8 8021D118 00000043 */  sra       $zero, $zero, 1
/* 4FCCFC 8021D11C 00000008 */  jr        $zero
/* 4FCD00 8021D120 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FCD04 8021D124 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCD08 8021D128 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCD0C 8021D12C 10000000 */  b         .L8021D130
.L8021D130:
/* 4FCD10 8021D130 00000000 */   nop      
/* 4FCD14 8021D134 00000000 */  nop       
/* 4FCD18 8021D138 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCD1C 8021D13C 00000020 */  add       $zero, $zero, $zero
/* 4FCD20 8021D140 00000014 */  dsllv     $zero, $zero, $zero
/* 4FCD24 8021D144 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCD28 8021D148 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCD2C 8021D14C 0000001D */  dmultu    $zero, $zero
/* 4FCD30 8021D150 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCD34 8021D154 00000000 */  nop       
/* 4FCD38 8021D158 0000001D */  dmultu    $zero, $zero
/* 4FCD3C 8021D15C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCD40 8021D160 00000002 */  srl       $zero, $zero, 0
/* 4FCD44 8021D164 00000043 */  sra       $zero, $zero, 1
/* 4FCD48 8021D168 00000002 */  srl       $zero, $zero, 0
/* 4FCD4C 8021D16C 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FCD50 8021D170 00000002 */  srl       $zero, $zero, 0
/* 4FCD54 8021D174 00000043 */  sra       $zero, $zero, 1
/* 4FCD58 8021D178 00000004 */  sllv      $zero, $zero, $zero
/* 4FCD5C 8021D17C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FCD60 8021D180 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCD64 8021D184 00000006 */  srlv      $zero, $zero, $zero
/* 4FCD68 8021D188 004B0003 */  .byte     0x00, 0x4b, 0x00, 0x03
/* 4FCD6C 8021D18C 00000043 */  sra       $zero, $zero, 1
/* 4FCD70 8021D190 00000004 */  sllv      $zero, $zero, $zero
/* 4FCD74 8021D194 8026B438 */  lb        $a2, -0x4bc8($at)
/* 4FCD78 8021D198 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCD7C 8021D19C 00000006 */  srlv      $zero, $zero, $zero
/* 4FCD80 8021D1A0 000000B4 */  teq       $zero, $zero, 2
/* 4FCD84 8021D1A4 00000043 */  sra       $zero, $zero, 1
/* 4FCD88 8021D1A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCD8C 8021D1AC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FCD90 8021D1B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCD94 8021D1B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCD98 8021D1B8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCD9C 8021D1BC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCDA0 8021D1C0 00000027 */  not       $zero, $zero
/* 4FCDA4 8021D1C4 00000002 */  srl       $zero, $zero, 0
/* 4FCDA8 8021D1C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCDAC 8021D1CC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FCDB0 8021D1D0 00000027 */  not       $zero, $zero
/* 4FCDB4 8021D1D4 00000002 */  srl       $zero, $zero, 0
/* 4FCDB8 8021D1D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCDBC 8021D1DC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FCDC0 8021D1E0 00000043 */  sra       $zero, $zero, 1
/* 4FCDC4 8021D1E4 00000009 */  jr        $zero
/* 4FCDC8 8021D1E8 8027BF38 */   lb       $a3, -0x40c8($at)
/* 4FCDCC 8021D1EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCDD0 8021D1F0 00000006 */  srlv      $zero, $zero, $zero
/* 4FCDD4 8021D1F4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCDD8 8021D1F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FCDDC 8021D1FC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FCDE0 8021D200 00000000 */  nop       
/* 4FCDE4 8021D204 0000000A */  movz      $zero, $zero, $zero
/* 4FCDE8 8021D208 00000000 */  nop       
/* 4FCDEC 8021D20C 00000043 */  sra       $zero, $zero, 1
/* 4FCDF0 8021D210 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCDF4 8021D214 8026D010 */  lb        $a2, -0x2ff0($at)
/* 4FCDF8 8021D218 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCDFC 8021D21C 00000006 */  srlv      $zero, $zero, $zero
/* 4FCE00 8021D220 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE04 8021D224 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE08 8021D228 00000043 */  sra       $zero, $zero, 1
/* 4FCE0C 8021D22C 00000002 */  srl       $zero, $zero, 0
/* 4FCE10 8021D230 802D62B8 */  lb        $t5, 0x62b8($at)
/* 4FCE14 8021D234 00000358 */  .byte     0x00, 0x00, 0x03, 0x58
/* 4FCE18 8021D238 00000043 */  sra       $zero, $zero, 1
/* 4FCE1C 8021D23C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE20 8021D240 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4FCE24 8021D244 00000020 */  add       $zero, $zero, $zero
/* 4FCE28 8021D248 00000000 */  nop       
/* 4FCE2C 8021D24C 00000023 */  negu      $zero, $zero
/* 4FCE30 8021D250 00000000 */  nop       
/* 4FCE34 8021D254 00000043 */  sra       $zero, $zero, 1
/* 4FCE38 8021D258 00000003 */  sra       $zero, $zero, 0
/* 4FCE3C 8021D25C 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FCE40 8021D260 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCE44 8021D264 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE48 8021D268 00000043 */  sra       $zero, $zero, 1
/* 4FCE4C 8021D26C 00000003 */  sra       $zero, $zero, 0
/* 4FCE50 8021D270 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FCE54 8021D274 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FCE58 8021D278 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE5C 8021D27C 00000002 */  srl       $zero, $zero, 0
/* 4FCE60 8021D280 00000000 */  nop       
/* 4FCE64 8021D284 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE68 8021D288 00000000 */  nop       
/* 4FCE6C 8021D28C 00000043 */  sra       $zero, $zero, 1
/* 4FCE70 8021D290 00000002 */  srl       $zero, $zero, 0
/* 4FCE74 8021D294 80269E28 */  lb        $a2, -0x61d8($at)
/* 4FCE78 8021D298 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCE7C 8021D29C 0000000A */  movz      $zero, $zero, $zero
/* 4FCE80 8021D2A0 00000002 */  srl       $zero, $zero, 0
/* 4FCE84 8021D2A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCE88 8021D2A8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE8C 8021D2AC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FCE90 8021D2B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCE94 8021D2B4 8021B28C */  lb        $at, -0x4d74($at)
/* 4FCE98 8021D2B8 00000002 */  srl       $zero, $zero, 0
/* 4FCE9C 8021D2BC 00000000 */  nop       
/* 4FCEA0 8021D2C0 00000013 */  mtlo      $zero
/* 4FCEA4 8021D2C4 00000000 */  nop       
/* 4FCEA8 8021D2C8 00000043 */  sra       $zero, $zero, 1
/* 4FCEAC 8021D2CC 00000003 */  sra       $zero, $zero, 0
/* 4FCEB0 8021D2D0 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4FCEB4 8021D2D4 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 4FCEB8 8021D2D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCEBC 8021D2DC 0000000C */  syscall   
/* 4FCEC0 8021D2E0 00000002 */  srl       $zero, $zero, 0
/* 4FCEC4 8021D2E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FCEC8 8021D2E8 000001F4 */  teq       $zero, $zero, 7
/* 4FCECC 8021D2EC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FCED0 8021D2F0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCED4 8021D2F4 8021B28C */  lb        $at, -0x4d74($at)
/* 4FCED8 8021D2F8 00000012 */  mflo      $zero
/* 4FCEDC 8021D2FC 00000000 */  nop       
/* 4FCEE0 8021D300 00000046 */  rotrv     $zero, $zero, $zero
/* 4FCEE4 8021D304 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCEE8 8021D308 8021BC74 */  lb        $at, -0x438c($at)
/* 4FCEEC 8021D30C 00000013 */  mtlo      $zero
/* 4FCEF0 8021D310 00000000 */  nop       
/* 4FCEF4 8021D314 00000002 */  srl       $zero, $zero, 0
/* 4FCEF8 8021D318 00000000 */  nop       
/* 4FCEFC 8021D31C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCF00 8021D320 00000000 */  nop       
/* 4FCF04 8021D324 00000000 */  nop       
/* 4FCF08 8021D328 00000000 */  nop       
/* 4FCF0C 8021D32C 00000000 */  nop       
/* 4FCF10 8021D330 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCF14 8021D334 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FCF18 8021D338 0000000C */  syscall   
/* 4FCF1C 8021D33C 00370000 */  .byte     0x00, 0x37, 0x00, 0x00
/* 4FCF20 8021D340 00000006 */  srlv      $zero, $zero, $zero
/* 4FCF24 8021D344 00370000 */  .byte     0x00, 0x37, 0x00, 0x00
/* 4FCF28 8021D348 00000009 */  jr        $zero
/* 4FCF2C 8021D34C 00370001 */   .byte    0x00, 0x37, 0x00, 0x01
/* 4FCF30 8021D350 00000008 */  jr        $zero
/* 4FCF34 8021D354 00370000 */   .byte    0x00, 0x37, 0x00, 0x00
/* 4FCF38 8021D358 0000000B */  movn      $zero, $zero, $zero
/* 4FCF3C 8021D35C 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FCF40 8021D360 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCF44 8021D364 00370000 */  .byte     0x00, 0x37, 0x00, 0x00
/* 4FCF48 8021D368 00000004 */  sllv      $zero, $zero, $zero
/* 4FCF4C 8021D36C 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FCF50 8021D370 00000003 */  sra       $zero, $zero, 0
/* 4FCF54 8021D374 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FCF58 8021D378 00000000 */  nop       
/* 4FCF5C 8021D37C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCF60 8021D380 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FCF64 8021D384 00000000 */  nop       
/* 4FCF68 8021D388 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCF6C 8021D38C 00370006 */  srlv      $zero, $s7, $at
/* 4FCF70 8021D390 00000000 */  nop       
/* 4FCF74 8021D394 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCF78 8021D398 00000000 */  nop       
/* 4FCF7C 8021D39C 00000000 */  nop       
/* 4FCF80 8021D3A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCF84 8021D3A4 00000000 */  nop       
/* 4FCF88 8021D3A8 00000002 */  srl       $zero, $zero, 0
/* 4FCF8C 8021D3AC 00000000 */  nop       
/* 4FCF90 8021D3B0 00000006 */  srlv      $zero, $zero, $zero
/* 4FCF94 8021D3B4 0000005F */  .byte     0x00, 0x00, 0x00, 0x5f
/* 4FCF98 8021D3B8 00000009 */  jr        $zero
/* 4FCF9C 8021D3BC 00000000 */   nop      
/* 4FCFA0 8021D3C0 00000007 */  srav      $zero, $zero, $zero
/* 4FCFA4 8021D3C4 00000000 */  nop       
/* 4FCFA8 8021D3C8 00000004 */  sllv      $zero, $zero, $zero
/* 4FCFAC 8021D3CC 00000032 */  tlt       $zero, $zero
/* 4FCFB0 8021D3D0 00000003 */  sra       $zero, $zero, 0
/* 4FCFB4 8021D3D4 00000000 */  nop       
/* 4FCFB8 8021D3D8 0000000B */  movn      $zero, $zero, $zero
/* 4FCFBC 8021D3DC 00000000 */  nop       
/* 4FCFC0 8021D3E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FCFC4 8021D3E4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4FCFC8 8021D3E8 0000000A */  movz      $zero, $zero, $zero
/* 4FCFCC 8021D3EC 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 4FCFD0 8021D3F0 00000008 */  jr        $zero
/* 4FCFD4 8021D3F4 0000005A */   .byte    0x00, 0x00, 0x00, 0x5a
/* 4FCFD8 8021D3F8 0000001F */  ddivu     $zero, $zero, $zero
/* 4FCFDC 8021D3FC 00000000 */  nop       
/* 4FCFE0 8021D400 00000020 */  add       $zero, $zero, $zero
/* 4FCFE4 8021D404 00000001 */  movf      $zero, $zero, $fcc0
/* 4FCFE8 8021D408 00000025 */  or        $zero, $zero, $zero
/* 4FCFEC 8021D40C 00000000 */  nop       
/* 4FCFF0 8021D410 00000022 */  neg       $zero, $zero
/* 4FCFF4 8021D414 00000000 */  nop       
/* 4FCFF8 8021D418 00000024 */  and       $zero, $zero, $zero
/* 4FCFFC 8021D41C 00000000 */  nop       
/* 4FD000 8021D420 00000023 */  negu      $zero, $zero
/* 4FD004 8021D424 00000000 */  nop       
/* 4FD008 8021D428 00000021 */  addu      $zero, $zero, $zero
/* 4FD00C 8021D42C 00000000 */  nop       
/* 4FD010 8021D430 00000026 */  xor       $zero, $zero, $zero
/* 4FD014 8021D434 00000000 */  nop       
/* 4FD018 8021D438 00000027 */  not       $zero, $zero
/* 4FD01C 8021D43C 00000000 */  nop       
/* 4FD020 8021D440 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4FD024 8021D444 00000000 */  nop       
/* 4FD028 8021D448 00000000 */  nop       
/* 4FD02C 8021D44C 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 4FD030 8021D450 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 4FD034 8021D454 002300FF */  .byte     0x00, 0x23, 0x00, 0xff
/* 4FD038 8021D458 8021D330 */  lb        $at, -0x2cd0($at)
/* 4FD03C 8021D45C 8021D394 */  lb        $at, -0x2c6c($at)
/* 4FD040 8021D460 00000010 */  mfhi      $zero
/* 4FD044 8021D464 00000000 */  nop       
/* 4FD048 8021D468 00F60000 */  .byte     0x00, 0xf6, 0x00, 0x00
/* 4FD04C 8021D46C 00000000 */  nop       
/* 4FD050 8021D470 00000000 */  nop       
/* 4FD054 8021D474 00190B05 */  .byte     0x00, 0x19, 0x0b, 0x05
/* 4FD058 8021D478 00010000 */  sll       $zero, $at, 0
/* 4FD05C 8021D47C 8021D44C */  lb        $at, -0x2bb4($at)
/* 4FD060 8021D480 8021D498 */  lb        $at, -0x2b68($at)
/* 4FD064 8021D484 8021D3A0 */  lb        $at, -0x2c60($at)
/* 4FD068 8021D488 46141428 */  .byte     0x46, 0x14, 0x14, 0x28
/* 4FD06C 8021D48C 5F005A01 */  bgtzl     $t8, .L80233C94
/* 4FD070 8021D490 26260000 */   addiu    $a2, $s1, 0
/* 4FD074 8021D494 F9210A21 */  bbit132   $t1, 1, .L8021FD1C
/* 4FD078 8021D498 00000043 */   sra      $zero, $zero, 1
/* 4FD07C 8021D49C 00000003 */  sra       $zero, $zero, 0
/* 4FD080 8021D4A0 80278930 */  lb        $a3, -0x76d0($at)
/* 4FD084 8021D4A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD088 8021D4A8 8021DCD4 */  lb        $at, -0x232c($at)
/* 4FD08C 8021D4AC 00000043 */  sra       $zero, $zero, 1
/* 4FD090 8021D4B0 00000003 */  sra       $zero, $zero, 0
/* 4FD094 8021D4B4 80278A94 */  lb        $a3, -0x756c($at)
/* 4FD098 8021D4B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD09C 8021D4BC 8021D4E4 */  lb        $at, -0x2b1c($at)
/* 4FD0A0 8021D4C0 00000043 */  sra       $zero, $zero, 1
/* 4FD0A4 8021D4C4 00000003 */  sra       $zero, $zero, 0
/* 4FD0A8 8021D4C8 80278C20 */  lb        $a3, -0x73e0($at)
/* 4FD0AC 8021D4CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD0B0 8021D4D0 8021D60C */  lb        $at, -0x29f4($at)
/* 4FD0B4 8021D4D4 00000002 */  srl       $zero, $zero, 0
/* 4FD0B8 8021D4D8 00000000 */  nop       
/* 4FD0BC 8021D4DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD0C0 8021D4E0 00000000 */  nop       
/* 4FD0C4 8021D4E4 00000002 */  srl       $zero, $zero, 0
/* 4FD0C8 8021D4E8 00000000 */  nop       
/* 4FD0CC 8021D4EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD0D0 8021D4F0 00000000 */  nop       
/* 4FD0D4 8021D4F4 00000043 */  sra       $zero, $zero, 1
/* 4FD0D8 8021D4F8 00000002 */  srl       $zero, $zero, 0
/* 4FD0DC 8021D4FC 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FD0E0 8021D500 00000002 */  srl       $zero, $zero, 0
/* 4FD0E4 8021D504 00000043 */  sra       $zero, $zero, 1
/* 4FD0E8 8021D508 00000002 */  srl       $zero, $zero, 0
/* 4FD0EC 8021D50C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4FD0F0 8021D510 00000014 */  dsllv     $zero, $zero, $zero
/* 4FD0F4 8021D514 00000043 */  sra       $zero, $zero, 1
/* 4FD0F8 8021D518 00000004 */  sllv      $zero, $zero, $zero
/* 4FD0FC 8021D51C 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FD100 8021D520 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD104 8021D524 00000004 */  sllv      $zero, $zero, $zero
/* 4FD108 8021D528 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD10C 8021D52C 00000043 */  sra       $zero, $zero, 1
/* 4FD110 8021D530 00000003 */  sra       $zero, $zero, 0
/* 4FD114 8021D534 8025385C */  lb        $a1, 0x385c($at)
/* 4FD118 8021D538 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD11C 8021D53C 00000322 */  .byte     0x00, 0x00, 0x03, 0x22
/* 4FD120 8021D540 00000043 */  sra       $zero, $zero, 1
/* 4FD124 8021D544 00000004 */  sllv      $zero, $zero, $zero
/* 4FD128 8021D548 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD12C 8021D54C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD130 8021D550 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD134 8021D554 00370004 */  sllv      $zero, $s7, $at
/* 4FD138 8021D558 00000008 */  jr        $zero
/* 4FD13C 8021D55C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD140 8021D560 0000000A */  movz      $zero, $zero, $zero
/* 4FD144 8021D564 00000043 */  sra       $zero, $zero, 1
/* 4FD148 8021D568 00000002 */  srl       $zero, $zero, 0
/* 4FD14C 8021D56C 80269EC4 */  lb        $a2, -0x613c($at)
/* 4FD150 8021D570 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD154 8021D574 00000043 */  sra       $zero, $zero, 1
/* 4FD158 8021D578 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FD15C 8021D57C 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FD160 8021D580 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD164 8021D584 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD168 8021D588 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD16C 8021D58C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD170 8021D590 00000043 */  sra       $zero, $zero, 1
/* 4FD174 8021D594 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FD178 8021D598 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4FD17C 8021D59C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD180 8021D5A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD184 8021D5A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD188 8021D5A8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD18C 8021D5AC 00000043 */  sra       $zero, $zero, 1
/* 4FD190 8021D5B0 00000003 */  sra       $zero, $zero, 0
/* 4FD194 8021D5B4 8025385C */  lb        $a1, 0x385c($at)
/* 4FD198 8021D5B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD19C 8021D5BC 00000321 */  .byte     0x00, 0x00, 0x03, 0x21
/* 4FD1A0 8021D5C0 00000043 */  sra       $zero, $zero, 1
/* 4FD1A4 8021D5C4 00000004 */  sllv      $zero, $zero, $zero
/* 4FD1A8 8021D5C8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD1AC 8021D5CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD1B0 8021D5D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD1B4 8021D5D4 00370003 */  .byte     0x00, 0x37, 0x00, 0x03
/* 4FD1B8 8021D5D8 00000008 */  jr        $zero
/* 4FD1BC 8021D5DC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD1C0 8021D5E0 0000000A */  movz      $zero, $zero, $zero
/* 4FD1C4 8021D5E4 00000043 */  sra       $zero, $zero, 1
/* 4FD1C8 8021D5E8 00000004 */  sllv      $zero, $zero, $zero
/* 4FD1CC 8021D5EC 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FD1D0 8021D5F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD1D4 8021D5F4 00000004 */  sllv      $zero, $zero, $zero
/* 4FD1D8 8021D5F8 00000000 */  nop       
/* 4FD1DC 8021D5FC 00000002 */  srl       $zero, $zero, 0
/* 4FD1E0 8021D600 00000000 */  nop       
/* 4FD1E4 8021D604 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD1E8 8021D608 00000000 */  nop       
/* 4FD1EC 8021D60C 00000043 */  sra       $zero, $zero, 1
/* 4FD1F0 8021D610 00000003 */  sra       $zero, $zero, 0
/* 4FD1F4 8021D614 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FD1F8 8021D618 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD1FC 8021D61C 00000000 */  nop       
/* 4FD200 8021D620 00000043 */  sra       $zero, $zero, 1
/* 4FD204 8021D624 00000003 */  sra       $zero, $zero, 0
/* 4FD208 8021D628 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FD20C 8021D62C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD210 8021D630 00000000 */  nop       
/* 4FD214 8021D634 00000043 */  sra       $zero, $zero, 1
/* 4FD218 8021D638 00000003 */  sra       $zero, $zero, 0
/* 4FD21C 8021D63C 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 4FD220 8021D640 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD224 8021D644 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD228 8021D648 00000014 */  dsllv     $zero, $zero, $zero
/* 4FD22C 8021D64C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD230 8021D650 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD234 8021D654 0000001D */  dmultu    $zero, $zero
/* 4FD238 8021D658 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD23C 8021D65C 00000009 */  jr        $zero
/* 4FD240 8021D660 0000001D */   dmultu   $zero, $zero
/* 4FD244 8021D664 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD248 8021D668 0000000A */  movz      $zero, $zero, $zero
/* 4FD24C 8021D66C 00000025 */  or        $zero, $zero, $zero
/* 4FD250 8021D670 00000002 */  srl       $zero, $zero, 0
/* 4FD254 8021D674 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD258 8021D678 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD25C 8021D67C 00000025 */  or        $zero, $zero, $zero
/* 4FD260 8021D680 00000002 */  srl       $zero, $zero, 0
/* 4FD264 8021D684 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD268 8021D688 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD26C 8021D68C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD270 8021D690 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD274 8021D694 80299044 */  lb        $t1, -0x6fbc($at)
/* 4FD278 8021D698 00000020 */  add       $zero, $zero, $zero
/* 4FD27C 8021D69C 00000000 */  nop       
/* 4FD280 8021D6A0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD284 8021D6A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD288 8021D6A8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4FD28C 8021D6AC 00000025 */  or        $zero, $zero, $zero
/* 4FD290 8021D6B0 00000002 */  srl       $zero, $zero, 0
/* 4FD294 8021D6B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD298 8021D6B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD29C 8021D6BC 00000025 */  or        $zero, $zero, $zero
/* 4FD2A0 8021D6C0 00000002 */  srl       $zero, $zero, 0
/* 4FD2A4 8021D6C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD2A8 8021D6C8 0037000A */  movz      $zero, $at, $s7
/* 4FD2AC 8021D6CC 00000025 */  or        $zero, $zero, $zero
/* 4FD2B0 8021D6D0 00000002 */  srl       $zero, $zero, 0
/* 4FD2B4 8021D6D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD2B8 8021D6D8 0037000B */  movn      $zero, $at, $s7
/* 4FD2BC 8021D6DC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD2C0 8021D6E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD2C4 8021D6E4 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4FD2C8 8021D6E8 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD2CC 8021D6EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD2D0 8021D6F0 00000024 */  and       $zero, $zero, $zero
/* 4FD2D4 8021D6F4 00000025 */  or        $zero, $zero, $zero
/* 4FD2D8 8021D6F8 00000002 */  srl       $zero, $zero, 0
/* 4FD2DC 8021D6FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD2E0 8021D700 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD2E4 8021D704 00000025 */  or        $zero, $zero, $zero
/* 4FD2E8 8021D708 00000002 */  srl       $zero, $zero, 0
/* 4FD2EC 8021D70C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD2F0 8021D710 0037000A */  movz      $zero, $at, $s7
/* 4FD2F4 8021D714 00000025 */  or        $zero, $zero, $zero
/* 4FD2F8 8021D718 00000002 */  srl       $zero, $zero, 0
/* 4FD2FC 8021D71C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD300 8021D720 0037000B */  movn      $zero, $at, $s7
/* 4FD304 8021D724 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD308 8021D728 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD30C 8021D72C 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 4FD310 8021D730 00000025 */  or        $zero, $zero, $zero
/* 4FD314 8021D734 00000002 */  srl       $zero, $zero, 0
/* 4FD318 8021D738 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD31C 8021D73C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD320 8021D740 00000025 */  or        $zero, $zero, $zero
/* 4FD324 8021D744 00000002 */  srl       $zero, $zero, 0
/* 4FD328 8021D748 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD32C 8021D74C 0037000B */  movn      $zero, $at, $s7
/* 4FD330 8021D750 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD334 8021D754 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD338 8021D758 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FD33C 8021D75C 00000002 */  srl       $zero, $zero, 0
/* 4FD340 8021D760 00000000 */  nop       
/* 4FD344 8021D764 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD348 8021D768 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD34C 8021D76C 0000000B */  movn      $zero, $zero, $zero
/* 4FD350 8021D770 00000025 */  or        $zero, $zero, $zero
/* 4FD354 8021D774 00000002 */  srl       $zero, $zero, 0
/* 4FD358 8021D778 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD35C 8021D77C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD360 8021D780 00000025 */  or        $zero, $zero, $zero
/* 4FD364 8021D784 00000002 */  srl       $zero, $zero, 0
/* 4FD368 8021D788 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD36C 8021D78C 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD370 8021D790 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD374 8021D794 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD378 8021D798 8029B998 */  lb        $t1, -0x4668($at)
/* 4FD37C 8021D79C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD380 8021D7A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD384 8021D7A4 00000021 */  addu      $zero, $zero, $zero
/* 4FD388 8021D7A8 00000025 */  or        $zero, $zero, $zero
/* 4FD38C 8021D7AC 00000002 */  srl       $zero, $zero, 0
/* 4FD390 8021D7B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD394 8021D7B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD398 8021D7B8 00000025 */  or        $zero, $zero, $zero
/* 4FD39C 8021D7BC 00000002 */  srl       $zero, $zero, 0
/* 4FD3A0 8021D7C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD3A4 8021D7C4 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD3A8 8021D7C8 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD3AC 8021D7CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD3B0 8021D7D0 8029B998 */  lb        $t1, -0x4668($at)
/* 4FD3B4 8021D7D4 00000025 */  or        $zero, $zero, $zero
/* 4FD3B8 8021D7D8 00000002 */  srl       $zero, $zero, 0
/* 4FD3BC 8021D7DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD3C0 8021D7E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD3C4 8021D7E4 00000025 */  or        $zero, $zero, $zero
/* 4FD3C8 8021D7E8 00000002 */  srl       $zero, $zero, 0
/* 4FD3CC 8021D7EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD3D0 8021D7F0 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD3D4 8021D7F4 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD3D8 8021D7F8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD3DC 8021D7FC 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FD3E0 8021D800 00000002 */  srl       $zero, $zero, 0
/* 4FD3E4 8021D804 00000000 */  nop       
/* 4FD3E8 8021D808 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD3EC 8021D80C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD3F0 8021D810 0000002F */  dsubu     $zero, $zero, $zero
/* 4FD3F4 8021D814 00000025 */  or        $zero, $zero, $zero
/* 4FD3F8 8021D818 00000002 */  srl       $zero, $zero, 0
/* 4FD3FC 8021D81C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD400 8021D820 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD404 8021D824 00000025 */  or        $zero, $zero, $zero
/* 4FD408 8021D828 00000002 */  srl       $zero, $zero, 0
/* 4FD40C 8021D82C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD410 8021D830 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD414 8021D834 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD418 8021D838 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD41C 8021D83C 8029A6FC */  lb        $t1, -0x5904($at)
/* 4FD420 8021D840 00000043 */  sra       $zero, $zero, 1
/* 4FD424 8021D844 00000003 */  sra       $zero, $zero, 0
/* 4FD428 8021D848 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FD42C 8021D84C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD430 8021D850 F24A8A80 */  scd       $t2, -0x7580($s2)
/* 4FD434 8021D854 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD438 8021D858 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD43C 8021D85C 8021D4F4 */  lb        $at, -0x2b0c($at)
/* 4FD440 8021D860 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD444 8021D864 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD448 8021D868 00000026 */  xor       $zero, $zero, $zero
/* 4FD44C 8021D86C 00000025 */  or        $zero, $zero, $zero
/* 4FD450 8021D870 00000002 */  srl       $zero, $zero, 0
/* 4FD454 8021D874 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD458 8021D878 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD45C 8021D87C 00000025 */  or        $zero, $zero, $zero
/* 4FD460 8021D880 00000002 */  srl       $zero, $zero, 0
/* 4FD464 8021D884 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD468 8021D888 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD46C 8021D88C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD470 8021D890 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD474 8021D894 8029A6FC */  lb        $t1, -0x5904($at)
/* 4FD478 8021D898 00000025 */  or        $zero, $zero, $zero
/* 4FD47C 8021D89C 00000002 */  srl       $zero, $zero, 0
/* 4FD480 8021D8A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD484 8021D8A4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD488 8021D8A8 00000025 */  or        $zero, $zero, $zero
/* 4FD48C 8021D8AC 00000002 */  srl       $zero, $zero, 0
/* 4FD490 8021D8B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD494 8021D8B4 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD498 8021D8B8 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD49C 8021D8BC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD4A0 8021D8C0 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FD4A4 8021D8C4 00000002 */  srl       $zero, $zero, 0
/* 4FD4A8 8021D8C8 00000000 */  nop       
/* 4FD4AC 8021D8CC 0000001D */  dmultu    $zero, $zero
/* 4FD4B0 8021D8D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD4B4 8021D8D4 00000017 */  dsrav     $zero, $zero, $zero
/* 4FD4B8 8021D8D8 0000001D */  dmultu    $zero, $zero
/* 4FD4BC 8021D8DC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD4C0 8021D8E0 00000019 */  multu     $zero, $zero
/* 4FD4C4 8021D8E4 0000001D */  dmultu    $zero, $zero
/* 4FD4C8 8021D8E8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD4CC 8021D8EC 0000001F */  ddivu     $zero, $zero, $zero
/* 4FD4D0 8021D8F0 00000025 */  or        $zero, $zero, $zero
/* 4FD4D4 8021D8F4 00000002 */  srl       $zero, $zero, 0
/* 4FD4D8 8021D8F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD4DC 8021D8FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD4E0 8021D900 00000025 */  or        $zero, $zero, $zero
/* 4FD4E4 8021D904 00000002 */  srl       $zero, $zero, 0
/* 4FD4E8 8021D908 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD4EC 8021D90C 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FD4F0 8021D910 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD4F4 8021D914 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD4F8 8021D918 8029AC70 */  lb        $t1, -0x5390($at)
/* 4FD4FC 8021D91C 00000020 */  add       $zero, $zero, $zero
/* 4FD500 8021D920 00000000 */  nop       
/* 4FD504 8021D924 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD508 8021D928 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD50C 8021D92C 0000001B */  divu      $zero, $zero, $zero
/* 4FD510 8021D930 00000056 */  drotrv    $zero, $zero, $zero
/* 4FD514 8021D934 00000000 */  nop       
/* 4FD518 8021D938 00000008 */  jr        $zero
/* 4FD51C 8021D93C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD520 8021D940 0000000A */  movz      $zero, $zero, $zero
/* 4FD524 8021D944 00000043 */  sra       $zero, $zero, 1
/* 4FD528 8021D948 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FD52C 8021D94C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 4FD530 8021D950 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD534 8021D954 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD538 8021D958 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD53C 8021D95C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD540 8021D960 00000043 */  sra       $zero, $zero, 1
/* 4FD544 8021D964 00000003 */  sra       $zero, $zero, 0
/* 4FD548 8021D968 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FD54C 8021D96C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD550 8021D970 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FD554 8021D974 00000010 */  mfhi      $zero
/* 4FD558 8021D978 00000002 */  srl       $zero, $zero, 0
/* 4FD55C 8021D97C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 4FD560 8021D980 00080000 */  sll       $zero, $t0, 0
/* 4FD564 8021D984 00000027 */  not       $zero, $zero
/* 4FD568 8021D988 00000002 */  srl       $zero, $zero, 0
/* 4FD56C 8021D98C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD570 8021D990 00000000 */  nop       
/* 4FD574 8021D994 00000027 */  not       $zero, $zero
/* 4FD578 8021D998 00000002 */  srl       $zero, $zero, 0
/* 4FD57C 8021D99C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD580 8021D9A0 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 4FD584 8021D9A4 00000012 */  mflo      $zero
/* 4FD588 8021D9A8 00000000 */  nop       
/* 4FD58C 8021D9AC 00000027 */  not       $zero, $zero
/* 4FD590 8021D9B0 00000002 */  srl       $zero, $zero, 0
/* 4FD594 8021D9B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD598 8021D9B8 00000000 */  nop       
/* 4FD59C 8021D9BC 00000027 */  not       $zero, $zero
/* 4FD5A0 8021D9C0 00000002 */  srl       $zero, $zero, 0
/* 4FD5A4 8021D9C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD5A8 8021D9C8 00000023 */  negu      $zero, $zero
/* 4FD5AC 8021D9CC 00000013 */  mtlo      $zero
/* 4FD5B0 8021D9D0 00000000 */  nop       
/* 4FD5B4 8021D9D4 00000043 */  sra       $zero, $zero, 1
/* 4FD5B8 8021D9D8 0000000F */  sync      
/* 4FD5BC 8021D9DC 802D829C */  lb        $t5, -0x7d64($at)
/* 4FD5C0 8021D9E0 0000001A */  div       $zero, $zero, $zero
/* 4FD5C4 8021D9E4 00000000 */  nop       
/* 4FD5C8 8021D9E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD5CC 8021D9EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD5D0 8021D9F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD5D4 8021D9F4 00000014 */  dsllv     $zero, $zero, $zero
/* 4FD5D8 8021D9F8 00000000 */  nop       
/* 4FD5DC 8021D9FC 00000000 */  nop       
/* 4FD5E0 8021DA00 00000000 */  nop       
/* 4FD5E4 8021DA04 00000000 */  nop       
/* 4FD5E8 8021DA08 00000000 */  nop       
/* 4FD5EC 8021DA0C 00000000 */  nop       
/* 4FD5F0 8021DA10 00000000 */  nop       
/* 4FD5F4 8021DA14 00000000 */  nop       
/* 4FD5F8 8021DA18 00000008 */  jr        $zero
/* 4FD5FC 8021DA1C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD600 8021DA20 00000014 */  dsllv     $zero, $zero, $zero
/* 4FD604 8021DA24 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FD608 8021DA28 00000000 */  nop       
/* 4FD60C 8021DA2C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FD610 8021DA30 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD614 8021DA34 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4FD618 8021DA38 00000043 */  sra       $zero, $zero, 1
/* 4FD61C 8021DA3C 00000004 */  sllv      $zero, $zero, $zero
/* 4FD620 8021DA40 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD624 8021DA44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD628 8021DA48 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD62C 8021DA4C 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FD630 8021DA50 00000008 */  jr        $zero
/* 4FD634 8021DA54 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD638 8021DA58 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD63C 8021DA5C 00000043 */  sra       $zero, $zero, 1
/* 4FD640 8021DA60 00000004 */  sllv      $zero, $zero, $zero
/* 4FD644 8021DA64 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD648 8021DA68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD64C 8021DA6C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD650 8021DA70 00370006 */  srlv      $zero, $s7, $at
/* 4FD654 8021DA74 00000008 */  jr        $zero
/* 4FD658 8021DA78 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD65C 8021DA7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD660 8021DA80 00000006 */  srlv      $zero, $zero, $zero
/* 4FD664 8021DA84 00000000 */  nop       
/* 4FD668 8021DA88 00000043 */  sra       $zero, $zero, 1
/* 4FD66C 8021DA8C 00000004 */  sllv      $zero, $zero, $zero
/* 4FD670 8021DA90 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD674 8021DA94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD678 8021DA98 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD67C 8021DA9C 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FD680 8021DAA0 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD684 8021DAA4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD688 8021DAA8 00000020 */  add       $zero, $zero, $zero
/* 4FD68C 8021DAAC 00000025 */  or        $zero, $zero, $zero
/* 4FD690 8021DAB0 00000002 */  srl       $zero, $zero, 0
/* 4FD694 8021DAB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD698 8021DAB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD69C 8021DABC 00000025 */  or        $zero, $zero, $zero
/* 4FD6A0 8021DAC0 00000002 */  srl       $zero, $zero, 0
/* 4FD6A4 8021DAC4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD6A8 8021DAC8 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD6AC 8021DACC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD6B0 8021DAD0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD6B4 8021DAD4 80299044 */  lb        $t1, -0x6fbc($at)
/* 4FD6B8 8021DAD8 00000008 */  jr        $zero
/* 4FD6BC 8021DADC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD6C0 8021DAE0 0000000A */  movz      $zero, $zero, $zero
/* 4FD6C4 8021DAE4 00000025 */  or        $zero, $zero, $zero
/* 4FD6C8 8021DAE8 00000002 */  srl       $zero, $zero, 0
/* 4FD6CC 8021DAEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD6D0 8021DAF0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD6D4 8021DAF4 00000025 */  or        $zero, $zero, $zero
/* 4FD6D8 8021DAF8 00000002 */  srl       $zero, $zero, 0
/* 4FD6DC 8021DAFC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD6E0 8021DB00 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD6E4 8021DB04 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD6E8 8021DB08 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD6EC 8021DB0C 8029AEC0 */  lb        $t1, -0x5140($at)
/* 4FD6F0 8021DB10 00000002 */  srl       $zero, $zero, 0
/* 4FD6F4 8021DB14 00000000 */  nop       
/* 4FD6F8 8021DB18 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD6FC 8021DB1C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD700 8021DB20 00000031 */  tgeu      $zero, $zero
/* 4FD704 8021DB24 00000025 */  or        $zero, $zero, $zero
/* 4FD708 8021DB28 00000002 */  srl       $zero, $zero, 0
/* 4FD70C 8021DB2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD710 8021DB30 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD714 8021DB34 00000025 */  or        $zero, $zero, $zero
/* 4FD718 8021DB38 00000002 */  srl       $zero, $zero, 0
/* 4FD71C 8021DB3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD720 8021DB40 00370001 */  .byte     0x00, 0x37, 0x00, 0x01
/* 4FD724 8021DB44 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD728 8021DB48 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD72C 8021DB4C 8029BFA0 */  lb        $t1, -0x4060($at)
/* 4FD730 8021DB50 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD734 8021DB54 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD738 8021DB58 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 4FD73C 8021DB5C 00000025 */  or        $zero, $zero, $zero
/* 4FD740 8021DB60 00000002 */  srl       $zero, $zero, 0
/* 4FD744 8021DB64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD748 8021DB68 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD74C 8021DB6C 00000025 */  or        $zero, $zero, $zero
/* 4FD750 8021DB70 00000002 */  srl       $zero, $zero, 0
/* 4FD754 8021DB74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD758 8021DB78 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD75C 8021DB7C 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD760 8021DB80 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD764 8021DB84 80299044 */  lb        $t1, -0x6fbc($at)
/* 4FD768 8021DB88 00000043 */  sra       $zero, $zero, 1
/* 4FD76C 8021DB8C 00000003 */  sra       $zero, $zero, 0
/* 4FD770 8021DB90 8025385C */  lb        $a1, 0x385c($at)
/* 4FD774 8021DB94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD778 8021DB98 00000322 */  .byte     0x00, 0x00, 0x03, 0x22
/* 4FD77C 8021DB9C 00000043 */  sra       $zero, $zero, 1
/* 4FD780 8021DBA0 00000004 */  sllv      $zero, $zero, $zero
/* 4FD784 8021DBA4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD788 8021DBA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD78C 8021DBAC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD790 8021DBB0 00370004 */  sllv      $zero, $s7, $at
/* 4FD794 8021DBB4 00000043 */  sra       $zero, $zero, 1
/* 4FD798 8021DBB8 00000004 */  sllv      $zero, $zero, $zero
/* 4FD79C 8021DBBC 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FD7A0 8021DBC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD7A4 8021DBC4 00000004 */  sllv      $zero, $zero, $zero
/* 4FD7A8 8021DBC8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD7AC 8021DBCC 00000008 */  jr        $zero
/* 4FD7B0 8021DBD0 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD7B4 8021DBD4 00000008 */  jr        $zero
/* 4FD7B8 8021DBD8 00000043 */   sra      $zero, $zero, 1
/* 4FD7BC 8021DBDC 00000002 */  srl       $zero, $zero, 0
/* 4FD7C0 8021DBE0 8027D32C */  lb        $a3, -0x2cd4($at)
/* 4FD7C4 8021DBE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD7C8 8021DBE8 00000043 */  sra       $zero, $zero, 1
/* 4FD7CC 8021DBEC 00000003 */  sra       $zero, $zero, 0
/* 4FD7D0 8021DBF0 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FD7D4 8021DBF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD7D8 8021DBF8 00000000 */  nop       
/* 4FD7DC 8021DBFC 00000043 */  sra       $zero, $zero, 1
/* 4FD7E0 8021DC00 00000002 */  srl       $zero, $zero, 0
/* 4FD7E4 8021DC04 8027C7B0 */  lb        $a3, -0x3850($at)
/* 4FD7E8 8021DC08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD7EC 8021DC0C 00000002 */  srl       $zero, $zero, 0
/* 4FD7F0 8021DC10 00000000 */  nop       
/* 4FD7F4 8021DC14 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD7F8 8021DC18 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD7FC 8021DC1C 0000003A */  dsrl      $zero, $zero, 0
/* 4FD800 8021DC20 00000025 */  or        $zero, $zero, $zero
/* 4FD804 8021DC24 00000002 */  srl       $zero, $zero, 0
/* 4FD808 8021DC28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD80C 8021DC2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD810 8021DC30 00000025 */  or        $zero, $zero, $zero
/* 4FD814 8021DC34 00000002 */  srl       $zero, $zero, 0
/* 4FD818 8021DC38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD81C 8021DC3C 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD820 8021DC40 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD824 8021DC44 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD828 8021DC48 8029C37C */  lb        $t1, -0x3c84($at)
/* 4FD82C 8021DC4C 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD830 8021DC50 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD834 8021DC54 00000016 */  dsrlv     $zero, $zero, $zero
/* 4FD838 8021DC58 00000025 */  or        $zero, $zero, $zero
/* 4FD83C 8021DC5C 00000002 */  srl       $zero, $zero, 0
/* 4FD840 8021DC60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD844 8021DC64 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD848 8021DC68 00000025 */  or        $zero, $zero, $zero
/* 4FD84C 8021DC6C 00000002 */  srl       $zero, $zero, 0
/* 4FD850 8021DC70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD854 8021DC74 00370009 */  .byte     0x00, 0x37, 0x00, 0x09
/* 4FD858 8021DC78 00000046 */  rotrv     $zero, $zero, $zero
/* 4FD85C 8021DC7C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD860 8021DC80 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 4FD864 8021DC84 00000002 */  srl       $zero, $zero, 0
/* 4FD868 8021DC88 00000000 */  nop       
/* 4FD86C 8021DC8C 0000001C */  dmult     $zero, $zero
/* 4FD870 8021DC90 00000000 */  nop       
/* 4FD874 8021DC94 00000023 */  negu      $zero, $zero
/* 4FD878 8021DC98 00000000 */  nop       
/* 4FD87C 8021DC9C 00000043 */  sra       $zero, $zero, 1
/* 4FD880 8021DCA0 00000003 */  sra       $zero, $zero, 0
/* 4FD884 8021DCA4 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FD888 8021DCA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD88C 8021DCAC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD890 8021DCB0 00000043 */  sra       $zero, $zero, 1
/* 4FD894 8021DCB4 00000003 */  sra       $zero, $zero, 0
/* 4FD898 8021DCB8 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FD89C 8021DCBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD8A0 8021DCC0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD8A4 8021DCC4 00000002 */  srl       $zero, $zero, 0
/* 4FD8A8 8021DCC8 00000000 */  nop       
/* 4FD8AC 8021DCCC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD8B0 8021DCD0 00000000 */  nop       
/* 4FD8B4 8021DCD4 00000043 */  sra       $zero, $zero, 1
/* 4FD8B8 8021DCD8 00000003 */  sra       $zero, $zero, 0
/* 4FD8BC 8021DCDC 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FD8C0 8021DCE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD8C4 8021DCE4 00000000 */  nop       
/* 4FD8C8 8021DCE8 00000043 */  sra       $zero, $zero, 1
/* 4FD8CC 8021DCEC 00000003 */  sra       $zero, $zero, 0
/* 4FD8D0 8021DCF0 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FD8D4 8021DCF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD8D8 8021DCF8 00000000 */  nop       
/* 4FD8DC 8021DCFC 00000043 */  sra       $zero, $zero, 1
/* 4FD8E0 8021DD00 00000003 */  sra       $zero, $zero, 0
/* 4FD8E4 8021DD04 8027C548 */  lb        $a3, -0x3ab8($at)
/* 4FD8E8 8021DD08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD8EC 8021DD0C 00000000 */  nop       
/* 4FD8F0 8021DD10 00000043 */  sra       $zero, $zero, 1
/* 4FD8F4 8021DD14 00000002 */  srl       $zero, $zero, 0
/* 4FD8F8 8021DD18 80269E28 */  lb        $a2, -0x61d8($at)
/* 4FD8FC 8021DD1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD900 8021DD20 0000000A */  movz      $zero, $zero, $zero
/* 4FD904 8021DD24 00000002 */  srl       $zero, $zero, 0
/* 4FD908 8021DD28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD90C 8021DD2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD910 8021DD30 00000043 */  sra       $zero, $zero, 1
/* 4FD914 8021DD34 00000004 */  sllv      $zero, $zero, $zero
/* 4FD918 8021DD38 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FD91C 8021DD3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD920 8021DD40 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD924 8021DD44 00370004 */  sllv      $zero, $s7, $at
/* 4FD928 8021DD48 00000043 */  sra       $zero, $zero, 1
/* 4FD92C 8021DD4C 00000004 */  sllv      $zero, $zero, $zero
/* 4FD930 8021DD50 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FD934 8021DD54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD938 8021DD58 00000004 */  sllv      $zero, $zero, $zero
/* 4FD93C 8021DD5C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD940 8021DD60 00000043 */  sra       $zero, $zero, 1
/* 4FD944 8021DD64 00000002 */  srl       $zero, $zero, 0
/* 4FD948 8021DD68 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FD94C 8021DD6C 0000003F */  dsra32    $zero, $zero, 0
/* 4FD950 8021DD70 00000043 */  sra       $zero, $zero, 1
/* 4FD954 8021DD74 00000002 */  srl       $zero, $zero, 0
/* 4FD958 8021DD78 8024EB24 */  lb        $a0, -0x14dc($at)
/* 4FD95C 8021DD7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD960 8021DD80 00000043 */  sra       $zero, $zero, 1
/* 4FD964 8021DD84 00000004 */  sllv      $zero, $zero, $zero
/* 4FD968 8021DD88 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4FD96C 8021DD8C FFFFFFFF */  sd        $ra, -1($ra)
/* 4FD970 8021DD90 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD974 8021DD94 00000000 */  nop       
/* 4FD978 8021DD98 00000043 */  sra       $zero, $zero, 1
/* 4FD97C 8021DD9C 00000002 */  srl       $zero, $zero, 0
/* 4FD980 8021DDA0 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4FD984 8021DDA4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FD988 8021DDA8 00000043 */  sra       $zero, $zero, 1
/* 4FD98C 8021DDAC 00000002 */  srl       $zero, $zero, 0
/* 4FD990 8021DDB0 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FD994 8021DDB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD998 8021DDB8 00000043 */  sra       $zero, $zero, 1
/* 4FD99C 8021DDBC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FD9A0 8021DDC0 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FD9A4 8021DDC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD9A8 8021DDC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD9AC 8021DDCC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD9B0 8021DDD0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD9B4 8021DDD4 00000027 */  not       $zero, $zero
/* 4FD9B8 8021DDD8 00000002 */  srl       $zero, $zero, 0
/* 4FD9BC 8021DDDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD9C0 8021DDE0 00000014 */  dsllv     $zero, $zero, $zero
/* 4FD9C4 8021DDE4 00000024 */  and       $zero, $zero, $zero
/* 4FD9C8 8021DDE8 00000002 */  srl       $zero, $zero, 0
/* 4FD9CC 8021DDEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD9D0 8021DDF0 00000000 */  nop       
/* 4FD9D4 8021DDF4 00000043 */  sra       $zero, $zero, 1
/* 4FD9D8 8021DDF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FD9DC 8021DDFC 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4FD9E0 8021DE00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FD9E4 8021DE04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FD9E8 8021DE08 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FD9EC 8021DE0C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FD9F0 8021DE10 00000008 */  jr        $zero
/* 4FD9F4 8021DE14 00000001 */   movf     $zero, $zero, $fcc0
/* 4FD9F8 8021DE18 0000000F */  sync      
/* 4FD9FC 8021DE1C 00000004 */  sllv      $zero, $zero, $zero
/* 4FDA00 8021DE20 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDA04 8021DE24 0000007B */  dsra      $zero, $zero, 1
/* 4FDA08 8021DE28 00000013 */  mtlo      $zero
/* 4FDA0C 8021DE2C 00000000 */  nop       
/* 4FDA10 8021DE30 00000043 */  sra       $zero, $zero, 1
/* 4FDA14 8021DE34 00000003 */  sra       $zero, $zero, 0
/* 4FDA18 8021DE38 8025385C */  lb        $a1, 0x385c($at)
/* 4FDA1C 8021DE3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDA20 8021DE40 00000322 */  .byte     0x00, 0x00, 0x03, 0x22
/* 4FDA24 8021DE44 00000043 */  sra       $zero, $zero, 1
/* 4FDA28 8021DE48 00000004 */  sllv      $zero, $zero, $zero
/* 4FDA2C 8021DE4C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDA30 8021DE50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDA34 8021DE54 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDA38 8021DE58 00370004 */  sllv      $zero, $s7, $at
/* 4FDA3C 8021DE5C 00000043 */  sra       $zero, $zero, 1
/* 4FDA40 8021DE60 00000004 */  sllv      $zero, $zero, $zero
/* 4FDA44 8021DE64 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FDA48 8021DE68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDA4C 8021DE6C 00000004 */  sllv      $zero, $zero, $zero
/* 4FDA50 8021DE70 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDA54 8021DE74 00000008 */  jr        $zero
/* 4FDA58 8021DE78 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDA5C 8021DE7C 00000008 */  jr        $zero
/* 4FDA60 8021DE80 00000043 */   sra      $zero, $zero, 1
/* 4FDA64 8021DE84 00000002 */  srl       $zero, $zero, 0
/* 4FDA68 8021DE88 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FDA6C 8021DE8C 00000013 */  mtlo      $zero
/* 4FDA70 8021DE90 00000043 */  sra       $zero, $zero, 1
/* 4FDA74 8021DE94 00000002 */  srl       $zero, $zero, 0
/* 4FDA78 8021DE98 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FDA7C 8021DE9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDA80 8021DEA0 00000043 */  sra       $zero, $zero, 1
/* 4FDA84 8021DEA4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDA88 8021DEA8 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FDA8C 8021DEAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDA90 8021DEB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDA94 8021DEB4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDA98 8021DEB8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FDA9C 8021DEBC 00000027 */  not       $zero, $zero
/* 4FDAA0 8021DEC0 00000002 */  srl       $zero, $zero, 0
/* 4FDAA4 8021DEC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDAA8 8021DEC8 00000014 */  dsllv     $zero, $zero, $zero
/* 4FDAAC 8021DECC 00000024 */  and       $zero, $zero, $zero
/* 4FDAB0 8021DED0 00000002 */  srl       $zero, $zero, 0
/* 4FDAB4 8021DED4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDAB8 8021DED8 00000000 */  nop       
/* 4FDABC 8021DEDC 00000043 */  sra       $zero, $zero, 1
/* 4FDAC0 8021DEE0 00000004 */  sllv      $zero, $zero, $zero
/* 4FDAC4 8021DEE4 8024E90C */  lb        $a0, -0x16f4($at)
/* 4FDAC8 8021DEE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDACC 8021DEEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDAD0 8021DEF0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FDAD4 8021DEF4 00000043 */  sra       $zero, $zero, 1
/* 4FDAD8 8021DEF8 00000002 */  srl       $zero, $zero, 0
/* 4FDADC 8021DEFC 8024EC6C */  lb        $a0, -0x1394($at)
/* 4FDAE0 8021DF00 0000015E */  .byte     0x00, 0x00, 0x01, 0x5e
/* 4FDAE4 8021DF04 00000043 */  sra       $zero, $zero, 1
/* 4FDAE8 8021DF08 00000002 */  srl       $zero, $zero, 0
/* 4FDAEC 8021DF0C 8024EA58 */  lb        $a0, -0x15a8($at)
/* 4FDAF0 8021DF10 0000002D */  daddu     $zero, $zero, $zero
/* 4FDAF4 8021DF14 00000043 */  sra       $zero, $zero, 1
/* 4FDAF8 8021DF18 00000004 */  sllv      $zero, $zero, $zero
/* 4FDAFC 8021DF1C 8024ECF8 */  lb        $a0, -0x1308($at)
/* 4FDB00 8021DF20 FFFFFFFF */  sd        $ra, -1($ra)
/* 4FDB04 8021DF24 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDB08 8021DF28 00000000 */  nop       
/* 4FDB0C 8021DF2C 00000043 */  sra       $zero, $zero, 1
/* 4FDB10 8021DF30 00000002 */  srl       $zero, $zero, 0
/* 4FDB14 8021DF34 8024EC08 */  lb        $a0, -0x13f8($at)
/* 4FDB18 8021DF38 00000014 */  dsllv     $zero, $zero, $zero
/* 4FDB1C 8021DF3C 00000043 */  sra       $zero, $zero, 1
/* 4FDB20 8021DF40 00000002 */  srl       $zero, $zero, 0
/* 4FDB24 8021DF44 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FDB28 8021DF48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDB2C 8021DF4C 00000043 */  sra       $zero, $zero, 1
/* 4FDB30 8021DF50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDB34 8021DF54 8026A820 */  lb        $a2, -0x57e0($at)
/* 4FDB38 8021DF58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDB3C 8021DF5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDB40 8021DF60 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDB44 8021DF64 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FDB48 8021DF68 00000043 */  sra       $zero, $zero, 1
/* 4FDB4C 8021DF6C 00000003 */  sra       $zero, $zero, 0
/* 4FDB50 8021DF70 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FDB54 8021DF74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDB58 8021DF78 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FDB5C 8021DF7C 00000010 */  mfhi      $zero
/* 4FDB60 8021DF80 00000002 */  srl       $zero, $zero, 0
/* 4FDB64 8021DF84 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FDB68 8021DF88 00080000 */  sll       $zero, $t0, 0
/* 4FDB6C 8021DF8C 00000027 */  not       $zero, $zero
/* 4FDB70 8021DF90 00000002 */  srl       $zero, $zero, 0
/* 4FDB74 8021DF94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDB78 8021DF98 00000008 */  jr        $zero
/* 4FDB7C 8021DF9C 00000027 */   not      $zero, $zero
/* 4FDB80 8021DFA0 00000002 */  srl       $zero, $zero, 0
/* 4FDB84 8021DFA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDB88 8021DFA8 FFFFFFFD */  sd        $ra, -3($ra)
/* 4FDB8C 8021DFAC 00000012 */  mflo      $zero
/* 4FDB90 8021DFB0 00000000 */  nop       
/* 4FDB94 8021DFB4 00000027 */  not       $zero, $zero
/* 4FDB98 8021DFB8 00000002 */  srl       $zero, $zero, 0
/* 4FDB9C 8021DFBC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDBA0 8021DFC0 00000014 */  dsllv     $zero, $zero, $zero
/* 4FDBA4 8021DFC4 00000013 */  mtlo      $zero
/* 4FDBA8 8021DFC8 00000000 */  nop       
/* 4FDBAC 8021DFCC 00000024 */  and       $zero, $zero, $zero
/* 4FDBB0 8021DFD0 00000002 */  srl       $zero, $zero, 0
/* 4FDBB4 8021DFD4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDBB8 8021DFD8 00000000 */  nop       
/* 4FDBBC 8021DFDC 00000043 */  sra       $zero, $zero, 1
/* 4FDBC0 8021DFE0 00000003 */  sra       $zero, $zero, 0
/* 4FDBC4 8021DFE4 8026B55C */  lb        $a2, -0x4aa4($at)
/* 4FDBC8 8021DFE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDBCC 8021DFEC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 4FDBD0 8021DFF0 00000043 */  sra       $zero, $zero, 1
/* 4FDBD4 8021DFF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDBD8 8021DFF8 8026F740 */  lb        $a2, -0x8c0($at)
/* 4FDBDC 8021DFFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDBE0 8021E000 00000002 */  srl       $zero, $zero, 0
/* 4FDBE4 8021E004 00000000 */  nop       
/* 4FDBE8 8021E008 00000000 */  nop       
/* 4FDBEC 8021E00C 00000043 */  sra       $zero, $zero, 1
/* 4FDBF0 8021E010 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDBF4 8021E014 8026A510 */  lb        $a2, -0x5af0($at)
/* 4FDBF8 8021E018 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDBFC 8021E01C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDC00 8021E020 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDC04 8021E024 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FDC08 8021E028 00000043 */  sra       $zero, $zero, 1
/* 4FDC0C 8021E02C 00000006 */  srlv      $zero, $zero, $zero
/* 4FDC10 8021E030 80278D08 */  lb        $a3, -0x72f8($at)
/* 4FDC14 8021E034 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDC18 8021E038 00000014 */  dsllv     $zero, $zero, $zero
/* 4FDC1C 8021E03C 00000000 */  nop       
/* 4FDC20 8021E040 00000000 */  nop       
/* 4FDC24 8021E044 00000000 */  nop       
/* 4FDC28 8021E048 00000003 */  sra       $zero, $zero, 0
/* 4FDC2C 8021E04C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDC30 8021E050 0000007B */  dsra      $zero, $zero, 1
/* 4FDC34 8021E054 00000043 */  sra       $zero, $zero, 1
/* 4FDC38 8021E058 00000003 */  sra       $zero, $zero, 0
/* 4FDC3C 8021E05C 8025385C */  lb        $a1, 0x385c($at)
/* 4FDC40 8021E060 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDC44 8021E064 00000321 */  .byte     0x00, 0x00, 0x03, 0x21
/* 4FDC48 8021E068 00000043 */  sra       $zero, $zero, 1
/* 4FDC4C 8021E06C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDC50 8021E070 8026AE40 */  lb        $a2, -0x51c0($at)
/* 4FDC54 8021E074 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDC58 8021E078 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDC5C 8021E07C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 4FDC60 8021E080 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 4FDC64 8021E084 00000043 */  sra       $zero, $zero, 1
/* 4FDC68 8021E088 00000004 */  sllv      $zero, $zero, $zero
/* 4FDC6C 8021E08C 8026CE8C */  lb        $a2, -0x3174($at)
/* 4FDC70 8021E090 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDC74 8021E094 00000004 */  sllv      $zero, $zero, $zero
/* 4FDC78 8021E098 00000000 */  nop       
/* 4FDC7C 8021E09C 00000043 */  sra       $zero, $zero, 1
/* 4FDC80 8021E0A0 00000004 */  sllv      $zero, $zero, $zero
/* 4FDC84 8021E0A4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDC88 8021E0A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDC8C 8021E0AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDC90 8021E0B0 00370003 */  .byte     0x00, 0x37, 0x00, 0x03
/* 4FDC94 8021E0B4 00000008 */  jr        $zero
/* 4FDC98 8021E0B8 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDC9C 8021E0BC 00000008 */  jr        $zero
/* 4FDCA0 8021E0C0 00000043 */   sra      $zero, $zero, 1
/* 4FDCA4 8021E0C4 00000004 */  sllv      $zero, $zero, $zero
/* 4FDCA8 8021E0C8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDCAC 8021E0CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDCB0 8021E0D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDCB4 8021E0D4 00370005 */  lsa       $zero, $at, $s7, 1
/* 4FDCB8 8021E0D8 00000043 */  sra       $zero, $zero, 1
/* 4FDCBC 8021E0DC 00000007 */  srav      $zero, $zero, $zero
/* 4FDCC0 8021E0E0 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4FDCC4 8021E0E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDCC8 8021E0E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDCCC 8021E0EC 00000000 */  nop       
/* 4FDCD0 8021E0F0 00000000 */  nop       
/* 4FDCD4 8021E0F4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDCD8 8021E0F8 00000010 */  mfhi      $zero
/* 4FDCDC 8021E0FC 00000014 */  dsllv     $zero, $zero, $zero
/* 4FDCE0 8021E100 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDCE4 8021E104 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDCE8 8021E108 0000001D */  dmultu    $zero, $zero
/* 4FDCEC 8021E10C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDCF0 8021E110 00000006 */  srlv      $zero, $zero, $zero
/* 4FDCF4 8021E114 0000001D */  dmultu    $zero, $zero
/* 4FDCF8 8021E118 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDCFC 8021E11C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDD00 8021E120 00000024 */  and       $zero, $zero, $zero
/* 4FDD04 8021E124 00000002 */  srl       $zero, $zero, 0
/* 4FDD08 8021E128 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FDD0C 8021E12C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDD10 8021E130 00000043 */  sra       $zero, $zero, 1
/* 4FDD14 8021E134 00000003 */  sra       $zero, $zero, 0
/* 4FDD18 8021E138 8026F230 */  lb        $a2, -0xdd0($at)
/* 4FDD1C 8021E13C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDD20 8021E140 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FDD24 8021E144 00000011 */  mthi      $zero
/* 4FDD28 8021E148 00000002 */  srl       $zero, $zero, 0
/* 4FDD2C 8021E14C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 4FDD30 8021E150 00080000 */  sll       $zero, $t0, 0
/* 4FDD34 8021E154 00000043 */  sra       $zero, $zero, 1
/* 4FDD38 8021E158 00000004 */  sllv      $zero, $zero, $zero
/* 4FDD3C 8021E15C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDD40 8021E160 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDD44 8021E164 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDD48 8021E168 00370006 */  srlv      $zero, $s7, $at
/* 4FDD4C 8021E16C 00000008 */  jr        $zero
/* 4FDD50 8021E170 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDD54 8021E174 00000002 */  srl       $zero, $zero, 0
/* 4FDD58 8021E178 00000013 */  mtlo      $zero
/* 4FDD5C 8021E17C 00000000 */  nop       
/* 4FDD60 8021E180 00000056 */  drotrv    $zero, $zero, $zero
/* 4FDD64 8021E184 00000000 */  nop       
/* 4FDD68 8021E188 00000008 */  jr        $zero
/* 4FDD6C 8021E18C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDD70 8021E190 00000006 */  srlv      $zero, $zero, $zero
/* 4FDD74 8021E194 00000043 */  sra       $zero, $zero, 1
/* 4FDD78 8021E198 00000003 */  sra       $zero, $zero, 0
/* 4FDD7C 8021E19C 8025385C */  lb        $a1, 0x385c($at)
/* 4FDD80 8021E1A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDD84 8021E1A4 000020DE */  .byte     0x00, 0x00, 0x20, 0xde
/* 4FDD88 8021E1A8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FDD8C 8021E1AC 00000000 */  nop       
/* 4FDD90 8021E1B0 00000043 */  sra       $zero, $zero, 1
/* 4FDD94 8021E1B4 00000004 */  sllv      $zero, $zero, $zero
/* 4FDD98 8021E1B8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDD9C 8021E1BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDDA0 8021E1C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDDA4 8021E1C4 00370007 */  srav      $zero, $s7, $at
/* 4FDDA8 8021E1C8 00000008 */  jr        $zero
/* 4FDDAC 8021E1CC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDDB0 8021E1D0 0000000A */  movz      $zero, $zero, $zero
/* 4FDDB4 8021E1D4 00000043 */  sra       $zero, $zero, 1
/* 4FDDB8 8021E1D8 00000004 */  sllv      $zero, $zero, $zero
/* 4FDDBC 8021E1DC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDDC0 8021E1E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDDC4 8021E1E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDDC8 8021E1E8 00370008 */  .byte     0x00, 0x37, 0x00, 0x08
/* 4FDDCC 8021E1EC 00000008 */  jr        $zero
/* 4FDDD0 8021E1F0 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDDD4 8021E1F4 00000002 */  srl       $zero, $zero, 0
/* 4FDDD8 8021E1F8 0000000A */  movz      $zero, $zero, $zero
/* 4FDDDC 8021E1FC 00000002 */  srl       $zero, $zero, 0
/* 4FDDE0 8021E200 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4FDDE4 8021E204 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FDDE8 8021E208 00000043 */  sra       $zero, $zero, 1
/* 4FDDEC 8021E20C 00000007 */  srav      $zero, $zero, $zero
/* 4FDDF0 8021E210 8027CFB8 */  lb        $a3, -0x3048($at)
/* 4FDDF4 8021E214 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDDF8 8021E218 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDDFC 8021E21C 80000000 */  lb        $zero, ($zero)
/* 4FDE00 8021E220 00000000 */  nop       
/* 4FDE04 8021E224 00000000 */  nop       
/* 4FDE08 8021E228 00000000 */  nop       
/* 4FDE0C 8021E22C 00000013 */  mtlo      $zero
/* 4FDE10 8021E230 00000000 */  nop       
/* 4FDE14 8021E234 00000008 */  jr        $zero
/* 4FDE18 8021E238 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDE1C 8021E23C 0000000F */  sync      
/* 4FDE20 8021E240 00000043 */  sra       $zero, $zero, 1
/* 4FDE24 8021E244 00000002 */  srl       $zero, $zero, 0
/* 4FDE28 8021E248 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FDE2C 8021E24C 00000002 */  srl       $zero, $zero, 0
/* 4FDE30 8021E250 00000043 */  sra       $zero, $zero, 1
/* 4FDE34 8021E254 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDE38 8021E258 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4FDE3C 8021E25C 00000043 */  sra       $zero, $zero, 1
/* 4FDE40 8021E260 00000003 */  sra       $zero, $zero, 0
/* 4FDE44 8021E264 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FDE48 8021E268 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDE4C 8021E26C F24A8A80 */  scd       $t2, -0x7580($s2)
/* 4FDE50 8021E270 00000046 */  rotrv     $zero, $zero, $zero
/* 4FDE54 8021E274 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDE58 8021E278 8021D4F4 */  lb        $at, -0x2b0c($at)
/* 4FDE5C 8021E27C 00000043 */  sra       $zero, $zero, 1
/* 4FDE60 8021E280 00000003 */  sra       $zero, $zero, 0
/* 4FDE64 8021E284 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FDE68 8021E288 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDE6C 8021E28C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDE70 8021E290 00000043 */  sra       $zero, $zero, 1
/* 4FDE74 8021E294 00000003 */  sra       $zero, $zero, 0
/* 4FDE78 8021E298 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FDE7C 8021E29C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDE80 8021E2A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDE84 8021E2A4 00000002 */  srl       $zero, $zero, 0
/* 4FDE88 8021E2A8 00000000 */  nop       
/* 4FDE8C 8021E2AC 00000020 */  add       $zero, $zero, $zero
/* 4FDE90 8021E2B0 00000000 */  nop       
/* 4FDE94 8021E2B4 00000023 */  negu      $zero, $zero
/* 4FDE98 8021E2B8 00000000 */  nop       
/* 4FDE9C 8021E2BC 00000043 */  sra       $zero, $zero, 1
/* 4FDEA0 8021E2C0 00000004 */  sllv      $zero, $zero, $zero
/* 4FDEA4 8021E2C4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDEA8 8021E2C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDEAC 8021E2CC 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDEB0 8021E2D0 00370006 */  srlv      $zero, $s7, $at
/* 4FDEB4 8021E2D4 00000008 */  jr        $zero
/* 4FDEB8 8021E2D8 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDEBC 8021E2DC 00000002 */  srl       $zero, $zero, 0
/* 4FDEC0 8021E2E0 00000056 */  drotrv    $zero, $zero, $zero
/* 4FDEC4 8021E2E4 00000000 */  nop       
/* 4FDEC8 8021E2E8 00000008 */  jr        $zero
/* 4FDECC 8021E2EC 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDED0 8021E2F0 00000006 */  srlv      $zero, $zero, $zero
/* 4FDED4 8021E2F4 00000043 */  sra       $zero, $zero, 1
/* 4FDED8 8021E2F8 00000003 */  sra       $zero, $zero, 0
/* 4FDEDC 8021E2FC 8025385C */  lb        $a1, 0x385c($at)
/* 4FDEE0 8021E300 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDEE4 8021E304 000020DE */  .byte     0x00, 0x00, 0x20, 0xde
/* 4FDEE8 8021E308 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4FDEEC 8021E30C 00000000 */  nop       
/* 4FDEF0 8021E310 00000043 */  sra       $zero, $zero, 1
/* 4FDEF4 8021E314 00000004 */  sllv      $zero, $zero, $zero
/* 4FDEF8 8021E318 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDEFC 8021E31C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDF00 8021E320 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDF04 8021E324 00370007 */  srav      $zero, $s7, $at
/* 4FDF08 8021E328 00000008 */  jr        $zero
/* 4FDF0C 8021E32C 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDF10 8021E330 0000000A */  movz      $zero, $zero, $zero
/* 4FDF14 8021E334 00000008 */  jr        $zero
/* 4FDF18 8021E338 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDF1C 8021E33C 00000002 */  srl       $zero, $zero, 0
/* 4FDF20 8021E340 00000043 */  sra       $zero, $zero, 1
/* 4FDF24 8021E344 00000002 */  srl       $zero, $zero, 0
/* 4FDF28 8021E348 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 4FDF2C 8021E34C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDF30 8021E350 00000043 */  sra       $zero, $zero, 1
/* 4FDF34 8021E354 00000008 */  jr        $zero
/* 4FDF38 8021E358 8027CCB4 */   lb       $a3, -0x334c($at)
/* 4FDF3C 8021E35C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDF40 8021E360 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDF44 8021E364 00000000 */  nop       
/* 4FDF48 8021E368 00000000 */  nop       
/* 4FDF4C 8021E36C 00000000 */  nop       
/* 4FDF50 8021E370 00000003 */  sra       $zero, $zero, 0
/* 4FDF54 8021E374 00000020 */  add       $zero, $zero, $zero
/* 4FDF58 8021E378 00000014 */  dsllv     $zero, $zero, $zero
/* 4FDF5C 8021E37C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDF60 8021E380 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4FDF64 8021E384 0000001D */  dmultu    $zero, $zero
/* 4FDF68 8021E388 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDF6C 8021E38C 00000000 */  nop       
/* 4FDF70 8021E390 0000001D */  dmultu    $zero, $zero
/* 4FDF74 8021E394 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDF78 8021E398 00000002 */  srl       $zero, $zero, 0
/* 4FDF7C 8021E39C 00000043 */  sra       $zero, $zero, 1
/* 4FDF80 8021E3A0 00000002 */  srl       $zero, $zero, 0
/* 4FDF84 8021E3A4 8024E61C */  lb        $a0, -0x19e4($at)
/* 4FDF88 8021E3A8 00000002 */  srl       $zero, $zero, 0
/* 4FDF8C 8021E3AC 00000008 */  jr        $zero
/* 4FDF90 8021E3B0 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDF94 8021E3B4 00000002 */  srl       $zero, $zero, 0
/* 4FDF98 8021E3B8 00000043 */  sra       $zero, $zero, 1
/* 4FDF9C 8021E3BC 00000004 */  sllv      $zero, $zero, $zero
/* 4FDFA0 8021E3C0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4FDFA4 8021E3C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDFA8 8021E3C8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDFAC 8021E3CC 00370008 */  .byte     0x00, 0x37, 0x00, 0x08
/* 4FDFB0 8021E3D0 00000008 */  jr        $zero
/* 4FDFB4 8021E3D4 00000001 */   movf     $zero, $zero, $fcc0
/* 4FDFB8 8021E3D8 0000000F */  sync      
/* 4FDFBC 8021E3DC 00000043 */  sra       $zero, $zero, 1
/* 4FDFC0 8021E3E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDFC4 8021E3E4 8027D7F0 */  lb        $a3, -0x2810($at)
/* 4FDFC8 8021E3E8 00000043 */  sra       $zero, $zero, 1
/* 4FDFCC 8021E3EC 00000003 */  sra       $zero, $zero, 0
/* 4FDFD0 8021E3F0 8026B654 */  lb        $a2, -0x49ac($at)
/* 4FDFD4 8021E3F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FDFD8 8021E3F8 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 4FDFDC 8021E3FC 00000046 */  rotrv     $zero, $zero, $zero
/* 4FDFE0 8021E400 00000001 */  movf      $zero, $zero, $fcc0
/* 4FDFE4 8021E404 8021D4F4 */  lb        $at, -0x2b0c($at)
/* 4FDFE8 8021E408 00000020 */  add       $zero, $zero, $zero
/* 4FDFEC 8021E40C 00000000 */  nop       
/* 4FDFF0 8021E410 00000023 */  negu      $zero, $zero
/* 4FDFF4 8021E414 00000000 */  nop       
/* 4FDFF8 8021E418 00000043 */  sra       $zero, $zero, 1
/* 4FDFFC 8021E41C 00000003 */  sra       $zero, $zero, 0
/* 4FE000 8021E420 80278B4C */  lb        $a3, -0x74b4($at)
/* 4FE004 8021E424 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FE008 8021E428 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE00C 8021E42C 00000043 */  sra       $zero, $zero, 1
/* 4FE010 8021E430 00000003 */  sra       $zero, $zero, 0
/* 4FE014 8021E434 8026F0EC */  lb        $a2, -0xf14($at)
/* 4FE018 8021E438 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4FE01C 8021E43C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE020 8021E440 00000002 */  srl       $zero, $zero, 0
/* 4FE024 8021E444 00000000 */  nop       
/* 4FE028 8021E448 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE02C 8021E44C 00000000 */  nop       
/* 4FE030 8021E450 00000043 */  sra       $zero, $zero, 1
/* 4FE034 8021E454 00000002 */  srl       $zero, $zero, 0
/* 4FE038 8021E458 802D9700 */  lb        $t5, -0x6900($at)
/* 4FE03C 8021E45C FFFFFFFF */  sd        $ra, -1($ra)
/* 4FE040 8021E460 00000043 */  sra       $zero, $zero, 1
/* 4FE044 8021E464 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE048 8021E468 80218360 */  lb        $at, -0x7ca0($at)
/* 4FE04C 8021E46C 00000002 */  srl       $zero, $zero, 0
/* 4FE050 8021E470 00000000 */  nop       
/* 4FE054 8021E474 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE058 8021E478 00000000 */  nop       
/* 4FE05C 8021E47C 00000002 */  srl       $zero, $zero, 0
/* 4FE060 8021E480 00000000 */  nop       
/* 4FE064 8021E484 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE068 8021E488 00000000 */  nop       
/* 4FE06C 8021E48C 8021EC20 */  lb        $at, -0x13e0($at)
/* 4FE070 8021E490 8021EC10 */  lb        $at, -0x13f0($at)
/* 4FE074 8021E494 8021EC00 */  lb        $at, -0x1400($at)
/* 4FE078 8021E498 8021E450 */  lb        $at, -0x1bb0($at)
/* 4FE07C 8021E49C 8021E47C */  lb        $at, -0x1b84($at)
/* 4FE080 8021E4A0 00000000 */  nop       
/* 4FE084 8021E4A4 00000000 */  nop       
/* 4FE088 8021E4A8 00000000 */  nop       
/* 4FE08C 8021E4AC 00000000 */  nop       
/* 4FE090 8021E4B0 00000000 */  nop       
/* 4FE094 8021E4B4 00000000 */  nop       
/* 4FE098 8021E4B8 00000000 */  nop       
/* 4FE09C 8021E4BC 00000000 */  nop       
/* 4FE0A0 8021E4C0 8021849C */  lb        $at, -0x7b64($at)
/* 4FE0A4 8021E4C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE0A8 8021E4C8 0000000A */  movz      $zero, $zero, $zero
/* 4FE0AC 8021E4CC 00000000 */  nop       
/* 4FE0B0 8021E4D0 00000000 */  nop       
/* 4FE0B4 8021E4D4 00000000 */  nop       
/* 4FE0B8 8021E4D8 00000000 */  nop       
/* 4FE0BC 8021E4DC 8021849C */  lb        $at, -0x7b64($at)
/* 4FE0C0 8021E4E0 00000002 */  srl       $zero, $zero, 0
/* 4FE0C4 8021E4E4 00000009 */  jr        $zero
/* 4FE0C8 8021E4E8 00000000 */   nop      
/* 4FE0CC 8021E4EC 00000000 */  nop       
/* 4FE0D0 8021E4F0 00000000 */  nop       
/* 4FE0D4 8021E4F4 00000000 */  nop       
/* 4FE0D8 8021E4F8 8021849C */  lb        $at, -0x7b64($at)
/* 4FE0DC 8021E4FC 00000000 */  nop       
/* 4FE0E0 8021E500 0000000A */  movz      $zero, $zero, $zero
/* 4FE0E4 8021E504 00000000 */  nop       
/* 4FE0E8 8021E508 00000000 */  nop       
/* 4FE0EC 8021E50C 00000000 */  nop       
/* 4FE0F0 8021E510 00000000 */  nop       
/* 4FE0F4 8021E514 8021849C */  lb        $at, -0x7b64($at)
/* 4FE0F8 8021E518 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE0FC 8021E51C 00000009 */  jr        $zero
/* 4FE100 8021E520 00000000 */   nop      
/* 4FE104 8021E524 00000000 */  nop       
/* 4FE108 8021E528 00000000 */  nop       
/* 4FE10C 8021E52C 00000000 */  nop       
/* 4FE110 8021E530 8021849C */  lb        $at, -0x7b64($at)
/* 4FE114 8021E534 00000002 */  srl       $zero, $zero, 0
/* 4FE118 8021E538 00000008 */  jr        $zero
/* 4FE11C 8021E53C 00000000 */   nop      
/* 4FE120 8021E540 00000000 */  nop       
/* 4FE124 8021E544 00000000 */  nop       
/* 4FE128 8021E548 00000000 */  nop       
/* 4FE12C 8021E54C 8021849C */  lb        $at, -0x7b64($at)
/* 4FE130 8021E550 00000000 */  nop       
/* 4FE134 8021E554 0000000A */  movz      $zero, $zero, $zero
/* 4FE138 8021E558 00000000 */  nop       
/* 4FE13C 8021E55C 00000000 */  nop       
/* 4FE140 8021E560 00000000 */  nop       
/* 4FE144 8021E564 00000000 */  nop       
/* 4FE148 8021E568 8021849C */  lb        $at, -0x7b64($at)
/* 4FE14C 8021E56C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE150 8021E570 00000009 */  jr        $zero
/* 4FE154 8021E574 00000000 */   nop      
/* 4FE158 8021E578 00000000 */  nop       
/* 4FE15C 8021E57C 00000000 */  nop       
/* 4FE160 8021E580 00000000 */  nop       
/* 4FE164 8021E584 8021849C */  lb        $at, -0x7b64($at)
/* 4FE168 8021E588 00000002 */  srl       $zero, $zero, 0
/* 4FE16C 8021E58C 00000008 */  jr        $zero
/* 4FE170 8021E590 00000000 */   nop      
/* 4FE174 8021E594 00000000 */  nop       
/* 4FE178 8021E598 00000000 */  nop       
/* 4FE17C 8021E59C 00000000 */  nop       
/* 4FE180 8021E5A0 8021849C */  lb        $at, -0x7b64($at)
/* 4FE184 8021E5A4 00000003 */  sra       $zero, $zero, 0
/* 4FE188 8021E5A8 00000007 */  srav      $zero, $zero, $zero
/* 4FE18C 8021E5AC 00000000 */  nop       
/* 4FE190 8021E5B0 00000000 */  nop       
/* 4FE194 8021E5B4 00000000 */  nop       
/* 4FE198 8021E5B8 00000000 */  nop       
/* 4FE19C 8021E5BC 8021849C */  lb        $at, -0x7b64($at)
/* 4FE1A0 8021E5C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE1A4 8021E5C4 0000000A */  movz      $zero, $zero, $zero
/* 4FE1A8 8021E5C8 00000000 */  nop       
/* 4FE1AC 8021E5CC 00000000 */  nop       
/* 4FE1B0 8021E5D0 00000000 */  nop       
/* 4FE1B4 8021E5D4 00000000 */  nop       
/* 4FE1B8 8021E5D8 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE1BC 8021E5DC 00000002 */  srl       $zero, $zero, 0
/* 4FE1C0 8021E5E0 00000009 */  jr        $zero
/* 4FE1C4 8021E5E4 00000000 */   nop      
/* 4FE1C8 8021E5E8 00000000 */  nop       
/* 4FE1CC 8021E5EC 00000000 */  nop       
/* 4FE1D0 8021E5F0 00000000 */  nop       
/* 4FE1D4 8021E5F4 8021849C */  lb        $at, -0x7b64($at)
/* 4FE1D8 8021E5F8 00000000 */  nop       
/* 4FE1DC 8021E5FC 0000000A */  movz      $zero, $zero, $zero
/* 4FE1E0 8021E600 00000000 */  nop       
/* 4FE1E4 8021E604 00000000 */  nop       
/* 4FE1E8 8021E608 00000000 */  nop       
/* 4FE1EC 8021E60C 00000000 */  nop       
/* 4FE1F0 8021E610 8021849C */  lb        $at, -0x7b64($at)
/* 4FE1F4 8021E614 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE1F8 8021E618 00000009 */  jr        $zero
/* 4FE1FC 8021E61C 00000000 */   nop      
/* 4FE200 8021E620 00000000 */  nop       
/* 4FE204 8021E624 00000000 */  nop       
/* 4FE208 8021E628 00000000 */  nop       
/* 4FE20C 8021E62C 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE210 8021E630 00000002 */  srl       $zero, $zero, 0
/* 4FE214 8021E634 00000008 */  jr        $zero
/* 4FE218 8021E638 00000000 */   nop      
/* 4FE21C 8021E63C 00000000 */  nop       
/* 4FE220 8021E640 00000000 */  nop       
/* 4FE224 8021E644 00000000 */  nop       
/* 4FE228 8021E648 8021849C */  lb        $at, -0x7b64($at)
/* 4FE22C 8021E64C 00000000 */  nop       
/* 4FE230 8021E650 0000000A */  movz      $zero, $zero, $zero
/* 4FE234 8021E654 00000000 */  nop       
/* 4FE238 8021E658 00000000 */  nop       
/* 4FE23C 8021E65C 00000000 */  nop       
/* 4FE240 8021E660 00000000 */  nop       
/* 4FE244 8021E664 8021849C */  lb        $at, -0x7b64($at)
/* 4FE248 8021E668 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE24C 8021E66C 00000009 */  jr        $zero
/* 4FE250 8021E670 00000000 */   nop      
/* 4FE254 8021E674 00000000 */  nop       
/* 4FE258 8021E678 00000000 */  nop       
/* 4FE25C 8021E67C 00000000 */  nop       
/* 4FE260 8021E680 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE264 8021E684 00000002 */  srl       $zero, $zero, 0
/* 4FE268 8021E688 00000008 */  jr        $zero
/* 4FE26C 8021E68C 00000000 */   nop      
/* 4FE270 8021E690 00000000 */  nop       
/* 4FE274 8021E694 00000000 */  nop       
/* 4FE278 8021E698 00000000 */  nop       
/* 4FE27C 8021E69C 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE280 8021E6A0 00000003 */  sra       $zero, $zero, 0
/* 4FE284 8021E6A4 00000007 */  srav      $zero, $zero, $zero
/* 4FE288 8021E6A8 00000000 */  nop       
/* 4FE28C 8021E6AC 00000000 */  nop       
/* 4FE290 8021E6B0 00000000 */  nop       
/* 4FE294 8021E6B4 00000000 */  nop       
/* 4FE298 8021E6B8 8021849C */  lb        $at, -0x7b64($at)
/* 4FE29C 8021E6BC 00000000 */  nop       
/* 4FE2A0 8021E6C0 0000000A */  movz      $zero, $zero, $zero
/* 4FE2A4 8021E6C4 00000000 */  nop       
/* 4FE2A8 8021E6C8 00000000 */  nop       
/* 4FE2AC 8021E6CC 00000000 */  nop       
/* 4FE2B0 8021E6D0 00000000 */  nop       
/* 4FE2B4 8021E6D4 8021849C */  lb        $at, -0x7b64($at)
/* 4FE2B8 8021E6D8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE2BC 8021E6DC 00000009 */  jr        $zero
/* 4FE2C0 8021E6E0 00000000 */   nop      
/* 4FE2C4 8021E6E4 00000000 */  nop       
/* 4FE2C8 8021E6E8 00000000 */  nop       
/* 4FE2CC 8021E6EC 00000000 */  nop       
/* 4FE2D0 8021E6F0 8021849C */  lb        $at, -0x7b64($at)
/* 4FE2D4 8021E6F4 00000002 */  srl       $zero, $zero, 0
/* 4FE2D8 8021E6F8 00000008 */  jr        $zero
/* 4FE2DC 8021E6FC 00000000 */   nop      
/* 4FE2E0 8021E700 00000000 */  nop       
/* 4FE2E4 8021E704 00000000 */  nop       
/* 4FE2E8 8021E708 00000000 */  nop       
/* 4FE2EC 8021E70C 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE2F0 8021E710 00000003 */  sra       $zero, $zero, 0
/* 4FE2F4 8021E714 00000007 */  srav      $zero, $zero, $zero
/* 4FE2F8 8021E718 00000000 */  nop       
/* 4FE2FC 8021E71C 00000000 */  nop       
/* 4FE300 8021E720 00000000 */  nop       
/* 4FE304 8021E724 00000000 */  nop       
/* 4FE308 8021E728 8021849C */  lb        $at, -0x7b64($at)
/* 4FE30C 8021E72C 00000000 */  nop       
/* 4FE310 8021E730 0000000A */  movz      $zero, $zero, $zero
/* 4FE314 8021E734 00000000 */  nop       
/* 4FE318 8021E738 00000000 */  nop       
/* 4FE31C 8021E73C 00000000 */  nop       
/* 4FE320 8021E740 00000000 */  nop       
/* 4FE324 8021E744 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE328 8021E748 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE32C 8021E74C 00000009 */  jr        $zero
/* 4FE330 8021E750 00000000 */   nop      
/* 4FE334 8021E754 00000000 */  nop       
/* 4FE338 8021E758 00000000 */  nop       
/* 4FE33C 8021E75C 00000000 */  nop       
/* 4FE340 8021E760 8021849C */  lb        $at, -0x7b64($at)
/* 4FE344 8021E764 00000002 */  srl       $zero, $zero, 0
/* 4FE348 8021E768 00000008 */  jr        $zero
/* 4FE34C 8021E76C 00000000 */   nop      
/* 4FE350 8021E770 00000000 */  nop       
/* 4FE354 8021E774 00000000 */  nop       
/* 4FE358 8021E778 00000000 */  nop       
/* 4FE35C 8021E77C 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE360 8021E780 00000003 */  sra       $zero, $zero, 0
/* 4FE364 8021E784 00000007 */  srav      $zero, $zero, $zero
/* 4FE368 8021E788 00000000 */  nop       
/* 4FE36C 8021E78C 00000000 */  nop       
/* 4FE370 8021E790 00000000 */  nop       
/* 4FE374 8021E794 00000000 */  nop       
/* 4FE378 8021E798 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE37C 8021E79C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE380 8021E7A0 0000000A */  movz      $zero, $zero, $zero
/* 4FE384 8021E7A4 00000000 */  nop       
/* 4FE388 8021E7A8 00000000 */  nop       
/* 4FE38C 8021E7AC 00000000 */  nop       
/* 4FE390 8021E7B0 00000000 */  nop       
/* 4FE394 8021E7B4 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE398 8021E7B8 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE39C 8021E7BC 0000000A */  movz      $zero, $zero, $zero
/* 4FE3A0 8021E7C0 00000000 */  nop       
/* 4FE3A4 8021E7C4 00000000 */  nop       
/* 4FE3A8 8021E7C8 00000000 */  nop       
/* 4FE3AC 8021E7CC 00000000 */  nop       
/* 4FE3B0 8021E7D0 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE3B4 8021E7D4 00000002 */  srl       $zero, $zero, 0
/* 4FE3B8 8021E7D8 00000009 */  jr        $zero
/* 4FE3BC 8021E7DC 00000000 */   nop      
/* 4FE3C0 8021E7E0 00000000 */  nop       
/* 4FE3C4 8021E7E4 00000000 */  nop       
/* 4FE3C8 8021E7E8 00000000 */  nop       
/* 4FE3CC 8021E7EC 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE3D0 8021E7F0 00000000 */  nop       
/* 4FE3D4 8021E7F4 0000000A */  movz      $zero, $zero, $zero
/* 4FE3D8 8021E7F8 00000000 */  nop       
/* 4FE3DC 8021E7FC 00000000 */  nop       
/* 4FE3E0 8021E800 00000000 */  nop       
/* 4FE3E4 8021E804 00000000 */  nop       
/* 4FE3E8 8021E808 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE3EC 8021E80C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE3F0 8021E810 00000009 */  jr        $zero
/* 4FE3F4 8021E814 00000000 */   nop      
/* 4FE3F8 8021E818 00000000 */  nop       
/* 4FE3FC 8021E81C 00000000 */  nop       
/* 4FE400 8021E820 00000000 */  nop       
/* 4FE404 8021E824 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE408 8021E828 00000002 */  srl       $zero, $zero, 0
/* 4FE40C 8021E82C 00000008 */  jr        $zero
/* 4FE410 8021E830 00000000 */   nop      
/* 4FE414 8021E834 00000000 */  nop       
/* 4FE418 8021E838 00000000 */  nop       
/* 4FE41C 8021E83C 00000000 */  nop       
/* 4FE420 8021E840 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE424 8021E844 00000000 */  nop       
/* 4FE428 8021E848 0000000A */  movz      $zero, $zero, $zero
/* 4FE42C 8021E84C 00000000 */  nop       
/* 4FE430 8021E850 00000000 */  nop       
/* 4FE434 8021E854 00000000 */  nop       
/* 4FE438 8021E858 00000000 */  nop       
/* 4FE43C 8021E85C 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE440 8021E860 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE444 8021E864 00000009 */  jr        $zero
/* 4FE448 8021E868 00000000 */   nop      
/* 4FE44C 8021E86C 00000000 */  nop       
/* 4FE450 8021E870 00000000 */  nop       
/* 4FE454 8021E874 00000000 */  nop       
/* 4FE458 8021E878 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE45C 8021E87C 00000002 */  srl       $zero, $zero, 0
/* 4FE460 8021E880 00000008 */  jr        $zero
/* 4FE464 8021E884 00000000 */   nop      
/* 4FE468 8021E888 00000000 */  nop       
/* 4FE46C 8021E88C 00000000 */  nop       
/* 4FE470 8021E890 00000000 */  nop       
/* 4FE474 8021E894 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE478 8021E898 00000003 */  sra       $zero, $zero, 0
/* 4FE47C 8021E89C 00000007 */  srav      $zero, $zero, $zero
/* 4FE480 8021E8A0 00000000 */  nop       
/* 4FE484 8021E8A4 00000000 */  nop       
/* 4FE488 8021E8A8 00000000 */  nop       
/* 4FE48C 8021E8AC 00000000 */  nop       
/* 4FE490 8021E8B0 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE494 8021E8B4 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE498 8021E8B8 0000000A */  movz      $zero, $zero, $zero
/* 4FE49C 8021E8BC 00000000 */  nop       
/* 4FE4A0 8021E8C0 00000000 */  nop       
/* 4FE4A4 8021E8C4 00000000 */  nop       
/* 4FE4A8 8021E8C8 00000000 */  nop       
/* 4FE4AC 8021E8CC 8021849C */  lb        $at, -0x7b64($at)
/* 4FE4B0 8021E8D0 00000002 */  srl       $zero, $zero, 0
/* 4FE4B4 8021E8D4 00000009 */  jr        $zero
/* 4FE4B8 8021E8D8 00000000 */   nop      
/* 4FE4BC 8021E8DC 00000000 */  nop       
/* 4FE4C0 8021E8E0 00000000 */  nop       
/* 4FE4C4 8021E8E4 00000000 */  nop       
/* 4FE4C8 8021E8E8 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE4CC 8021E8EC 00000000 */  nop       
/* 4FE4D0 8021E8F0 0000000A */  movz      $zero, $zero, $zero
/* 4FE4D4 8021E8F4 00000000 */  nop       
/* 4FE4D8 8021E8F8 00000000 */  nop       
/* 4FE4DC 8021E8FC 00000000 */  nop       
/* 4FE4E0 8021E900 00000000 */  nop       
/* 4FE4E4 8021E904 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE4E8 8021E908 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE4EC 8021E90C 00000009 */  jr        $zero
/* 4FE4F0 8021E910 00000000 */   nop      
/* 4FE4F4 8021E914 00000000 */  nop       
/* 4FE4F8 8021E918 00000000 */  nop       
/* 4FE4FC 8021E91C 00000000 */  nop       
/* 4FE500 8021E920 8021849C */  lb        $at, -0x7b64($at)
/* 4FE504 8021E924 00000002 */  srl       $zero, $zero, 0
/* 4FE508 8021E928 00000008 */  jr        $zero
/* 4FE50C 8021E92C 00000000 */   nop      
/* 4FE510 8021E930 00000000 */  nop       
/* 4FE514 8021E934 00000000 */  nop       
/* 4FE518 8021E938 00000000 */  nop       
/* 4FE51C 8021E93C 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE520 8021E940 00000000 */  nop       
/* 4FE524 8021E944 0000000A */  movz      $zero, $zero, $zero
/* 4FE528 8021E948 00000000 */  nop       
/* 4FE52C 8021E94C 00000000 */  nop       
/* 4FE530 8021E950 00000000 */  nop       
/* 4FE534 8021E954 00000000 */  nop       
/* 4FE538 8021E958 8021849C */  lb        $at, -0x7b64($at)
/* 4FE53C 8021E95C 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE540 8021E960 00000009 */  jr        $zero
/* 4FE544 8021E964 00000000 */   nop      
/* 4FE548 8021E968 00000000 */  nop       
/* 4FE54C 8021E96C 00000000 */  nop       
/* 4FE550 8021E970 00000000 */  nop       
/* 4FE554 8021E974 8021849C */  lb        $at, -0x7b64($at)
/* 4FE558 8021E978 00000002 */  srl       $zero, $zero, 0
/* 4FE55C 8021E97C 00000008 */  jr        $zero
/* 4FE560 8021E980 00000000 */   nop      
/* 4FE564 8021E984 00000000 */  nop       
/* 4FE568 8021E988 00000000 */  nop       
/* 4FE56C 8021E98C 00000000 */  nop       
/* 4FE570 8021E990 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE574 8021E994 00000000 */  nop       
/* 4FE578 8021E998 0000000A */  movz      $zero, $zero, $zero
/* 4FE57C 8021E99C 00000000 */  nop       
/* 4FE580 8021E9A0 00000000 */  nop       
/* 4FE584 8021E9A4 00000000 */  nop       
/* 4FE588 8021E9A8 00000000 */  nop       
/* 4FE58C 8021E9AC 8021849C */  lb        $at, -0x7b64($at)
/* 4FE590 8021E9B0 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE594 8021E9B4 00000009 */  jr        $zero
/* 4FE598 8021E9B8 00000000 */   nop      
/* 4FE59C 8021E9BC 00000000 */  nop       
/* 4FE5A0 8021E9C0 00000000 */  nop       
/* 4FE5A4 8021E9C4 00000000 */  nop       
/* 4FE5A8 8021E9C8 8021D470 */  lb        $at, -0x2b90($at)
/* 4FE5AC 8021E9CC 00000002 */  srl       $zero, $zero, 0
/* 4FE5B0 8021E9D0 00000008 */  jr        $zero
/* 4FE5B4 8021E9D4 00000000 */   nop      
/* 4FE5B8 8021E9D8 00000000 */  nop       
/* 4FE5BC 8021E9DC 00000000 */  nop       
/* 4FE5C0 8021E9E0 00000000 */  nop       
/* 4FE5C4 8021E9E4 8021A9FC */  lb        $at, -0x5604($at)
/* 4FE5C8 8021E9E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FE5CC 8021E9EC 0000000A */  movz      $zero, $zero, $zero
/* 4FE5D0 8021E9F0 00000000 */  nop       
/* 4FE5D4 8021E9F4 00000000 */  nop       
/* 4FE5D8 8021E9F8 00000000 */  nop       
/* 4FE5DC 8021E9FC 00000000 */  nop       
/* 4FE5E0 8021EA00 8021A9FC */  lb        $at, -0x5604($at)
/* 4FE5E4 8021EA04 00000006 */  srlv      $zero, $zero, $zero
/* 4FE5E8 8021EA08 00000009 */  jr        $zero
/* 4FE5EC 8021EA0C 00000000 */   nop      
/* 4FE5F0 8021EA10 00000000 */  nop       
/* 4FE5F4 8021EA14 00000000 */  nop       
/* 4FE5F8 8021EA18 00000000 */  nop       
/* 4FE5FC 8021EA1C 8021A9FC */  lb        $at, -0x5604($at)
/* 4FE600 8021EA20 00000004 */  sllv      $zero, $zero, $zero
/* 4FE604 8021EA24 0000000A */  movz      $zero, $zero, $zero
/* 4FE608 8021EA28 00000000 */  nop       
/* 4FE60C 8021EA2C 00000000 */  nop       
/* 4FE610 8021EA30 00000000 */  nop       
/* 4FE614 8021EA34 00000000 */  nop       
/* 4FE618 8021EA38 8021A9FC */  lb        $at, -0x5604($at)
/* 4FE61C 8021EA3C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4FE620 8021EA40 00000009 */  jr        $zero
/* 4FE624 8021EA44 00000000 */   nop      
/* 4FE628 8021EA48 00000000 */  nop       
/* 4FE62C 8021EA4C 00000000 */  nop       
/* 4FE630 8021EA50 00000000 */  nop       
/* 4FE634 8021EA54 8021A9FC */  lb        $at, -0x5604($at)
/* 4FE638 8021EA58 00000006 */  srlv      $zero, $zero, $zero
/* 4FE63C 8021EA5C 00000008 */  jr        $zero
/* 4FE640 8021EA60 00000000 */   nop      
/* 4FE644 8021EA64 00000000 */  nop       
/* 4FE648 8021EA68 00000000 */  nop       
/* 4FE64C 8021EA6C 00000000 */  nop       
/* 4FE650 8021EA70 8021EE50 */  lb        $at, -0x11b0($at)
/* 4FE654 8021EA74 00000002 */  srl       $zero, $zero, 0
/* 4FE658 8021EA78 8021E4C0 */  lb        $at, -0x1b40($at)
/* 4FE65C 8021EA7C 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE660 8021EA80 00000000 */  nop       
/* 4FE664 8021EA84 8021EE38 */  lb        $at, -0x11c8($at)
/* 4FE668 8021EA88 00000003 */  sra       $zero, $zero, 0
/* 4FE66C 8021EA8C 8021E4F8 */  lb        $at, -0x1b08($at)
/* 4FE670 8021EA90 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE674 8021EA94 00000000 */  nop       
/* 4FE678 8021EA98 8021EE20 */  lb        $at, -0x11e0($at)
/* 4FE67C 8021EA9C 00000004 */  sllv      $zero, $zero, $zero
/* 4FE680 8021EAA0 8021E54C */  lb        $at, -0x1ab4($at)
/* 4FE684 8021EAA4 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE688 8021EAA8 00000000 */  nop       
/* 4FE68C 8021EAAC 8021EDFC */  lb        $at, -0x1204($at)
/* 4FE690 8021EAB0 00000002 */  srl       $zero, $zero, 0
/* 4FE694 8021EAB4 8021E5BC */  lb        $at, -0x1a44($at)
/* 4FE698 8021EAB8 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE69C 8021EABC 00000000 */  nop       
/* 4FE6A0 8021EAC0 8021EDD4 */  lb        $at, -0x122c($at)
/* 4FE6A4 8021EAC4 00000003 */  sra       $zero, $zero, 0
/* 4FE6A8 8021EAC8 8021E5F4 */  lb        $at, -0x1a0c($at)
/* 4FE6AC 8021EACC 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE6B0 8021EAD0 00000000 */  nop       
/* 4FE6B4 8021EAD4 8021EDAC */  lb        $at, -0x1254($at)
/* 4FE6B8 8021EAD8 00000004 */  sllv      $zero, $zero, $zero
/* 4FE6BC 8021EADC 8021E648 */  lb        $at, -0x19b8($at)
/* 4FE6C0 8021EAE0 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE6C4 8021EAE4 00000000 */  nop       
/* 4FE6C8 8021EAE8 8021ED84 */  lb        $at, -0x127c($at)
/* 4FE6CC 8021EAEC 00000004 */  sllv      $zero, $zero, $zero
/* 4FE6D0 8021EAF0 8021E6B8 */  lb        $at, -0x1948($at)
/* 4FE6D4 8021EAF4 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE6D8 8021EAF8 00000000 */  nop       
/* 4FE6DC 8021EAFC 8021ED3C */  lb        $at, -0x12c4($at)
/* 4FE6E0 8021EB00 00000004 */  sllv      $zero, $zero, $zero
/* 4FE6E4 8021EB04 8021E728 */  lb        $at, -0x18d8($at)
/* 4FE6E8 8021EB08 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE6EC 8021EB0C 00000000 */  nop       
/* 4FE6F0 8021EB10 8021ED28 */  lb        $at, -0x12d8($at)
/* 4FE6F4 8021EB14 00000001 */  movf      $zero, $zero, $fcc0
/* 4FE6F8 8021EB18 8021E798 */  lb        $at, -0x1868($at)
/* 4FE6FC 8021EB1C 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE700 8021EB20 00000000 */  nop       
/* 4FE704 8021EB24 8021ED14 */  lb        $at, -0x12ec($at)
/* 4FE708 8021EB28 00000002 */  srl       $zero, $zero, 0
/* 4FE70C 8021EB2C 8021E7B4 */  lb        $at, -0x184c($at)
/* 4FE710 8021EB30 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE714 8021EB34 00000000 */  nop       
/* 4FE718 8021EB38 8021ED00 */  lb        $at, -0x1300($at)
/* 4FE71C 8021EB3C 00000003 */  sra       $zero, $zero, 0
/* 4FE720 8021EB40 8021E7EC */  lb        $at, -0x1814($at)
/* 4FE724 8021EB44 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE728 8021EB48 00000000 */  nop       
/* 4FE72C 8021EB4C 8021ECEC */  lb        $at, -0x1314($at)
/* 4FE730 8021EB50 00000004 */  sllv      $zero, $zero, $zero
/* 4FE734 8021EB54 8021E840 */  lb        $at, -0x17c0($at)
/* 4FE738 8021EB58 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE73C 8021EB5C 00000000 */  nop       
/* 4FE740 8021EB60 8021ECC8 */  lb        $at, -0x1338($at)
/* 4FE744 8021EB64 00000002 */  srl       $zero, $zero, 0
/* 4FE748 8021EB68 8021E8B0 */  lb        $at, -0x1750($at)
/* 4FE74C 8021EB6C 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE750 8021EB70 00000000 */  nop       
/* 4FE754 8021EB74 8021ECA0 */  lb        $at, -0x1360($at)
/* 4FE758 8021EB78 00000003 */  sra       $zero, $zero, 0
/* 4FE75C 8021EB7C 8021E8E8 */  lb        $at, -0x1718($at)
/* 4FE760 8021EB80 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE764 8021EB84 00000000 */  nop       
/* 4FE768 8021EB88 8021EC78 */  lb        $at, -0x1388($at)
/* 4FE76C 8021EB8C 00000003 */  sra       $zero, $zero, 0
/* 4FE770 8021EB90 8021E93C */  lb        $at, -0x16c4($at)
/* 4FE774 8021EB94 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE778 8021EB98 00000000 */  nop       
/* 4FE77C 8021EB9C 8021EC40 */  lb        $at, -0x13c0($at)
/* 4FE780 8021EBA0 00000003 */  sra       $zero, $zero, 0
/* 4FE784 8021EBA4 8021E990 */  lb        $at, -0x1670($at)
/* 4FE788 8021EBA8 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE78C 8021EBAC 00000000 */  nop       
/* 4FE790 8021EBB0 8021EC34 */  lb        $at, -0x13cc($at)
/* 4FE794 8021EBB4 00000002 */  srl       $zero, $zero, 0
/* 4FE798 8021EBB8 8021E9E4 */  lb        $at, -0x161c($at)
/* 4FE79C 8021EBBC 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE7A0 8021EBC0 00000000 */  nop       
/* 4FE7A4 8021EBC4 8021EC28 */  lb        $at, -0x13d8($at)
/* 4FE7A8 8021EBC8 00000003 */  sra       $zero, $zero, 0
/* 4FE7AC 8021EBCC 8021EA1C */  lb        $at, -0x15e4($at)
/* 4FE7B0 8021EBD0 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE7B4 8021EBD4 00000000 */  nop       
/* 4FE7B8 8021EBD8 00000000 */  nop       
/* 4FE7BC 8021EBDC 00000000 */  nop       
/* 4FE7C0 8021EBE0 00000000 */  nop       
/* 4FE7C4 8021EBE4 00000000 */  nop       
/* 4FE7C8 8021EBE8 00000000 */  nop       
/* 4FE7CC 8021EBEC 8021EE68 */  lb        $at, -0x1198($at)
/* 4FE7D0 8021EBF0 8021E48C */  lb        $at, -0x1b74($at)
/* 4FE7D4 8021EBF4 00000000 */  nop       
/* 4FE7D8 8021EBF8 00000000 */  nop       
/* 4FE7DC 8021EBFC 00000000 */  nop       
/* 4FE7E0 8021EC00 6D696D5F */  ldr       $t1, 0x6d5f($t3)
/* 4FE7E4 8021EC04 62743031 */  daddi     $s4, $s3, 0x3031
/* 4FE7E8 8021EC08 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4FE7EC 8021EC0C 00000000 */  nop       
/* 4FE7F0 8021EC10 6D696D5F */  ldr       $t1, 0x6d5f($t3)
/* 4FE7F4 8021EC14 62743031 */  daddi     $s4, $s3, 0x3031
/* 4FE7F8 8021EC18 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4FE7FC 8021EC1C 70650000 */  madd      $v1, $a1
/* 4FE800 8021EC20 6D696D5F */  ldr       $t1, 0x6d5f($t3)
/* 4FE804 8021EC24 74657800 */  jalx      0x8195e000
/* 4FE808 8021EC28 836E8362 */   lb       $t6, -0x7c9e($k1)
/* 4FE80C 8021EC2C 8360815B */  lb        $zero, -0x7ea5($k1)
/* 4FE810 8021EC30 78330000 */  andi.b    $w0, $w0, 0x33
/* 4FE814 8021EC34 836E8362 */  lb        $t6, -0x7c9e($k1)
/* 4FE818 8021EC38 8360815B */  lb        $zero, -0x7ea5($k1)
/* 4FE81C 8021EC3C 78320000 */  andi.b    $w0, $w0, 0x32
/* 4FE820 8021EC40 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE824 8021EC44 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE828 8021EC48 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE82C 8021EC4C 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE830 8021EC50 2C834F83 */  sltiu     $v1, $a0, 0x4f83
/* 4FE834 8021EC54 8A815B83 */  lwl       $at, 0x5b83($s4)
/* 4FE838 8021EC58 93836083 */  lbu       $v1, 0x6083($gp)
/* 4FE83C 8021EC5C 87838D83 */  lh        $v1, -0x727d($gp)
/* 4FE840 8021EC60 7B83932C */  .byte     0x7b, 0x83, 0x93, 0x2c
/* 4FE844 8021EC64 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE848 8021EC68 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE84C 8021EC6C 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE850 8021EC70 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE854 8021EC74 00000000 */  nop       
/* 4FE858 8021EC78 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE85C 8021EC7C 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE860 8021EC80 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE864 8021EC84 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE868 8021EC88 2C834F83 */  sltiu     $v1, $a0, 0x4f83
/* 4FE86C 8021EC8C 8A815B83 */  lwl       $at, 0x5b83($s4)
/* 4FE870 8021EC90 93836083 */  lbu       $v1, 0x6083($gp)
/* 4FE874 8021EC94 87838D83 */  lh        $v1, -0x727d($gp)
/* 4FE878 8021EC98 7B839378 */  .byte     0x7b, 0x83, 0x93, 0x78
/* 4FE87C 8021EC9C 32000000 */  andi      $zero, $s0, 0
/* 4FE880 8021ECA0 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE884 8021ECA4 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE888 8021ECA8 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE88C 8021ECAC 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE890 8021ECB0 78322C83 */  .byte     0x78, 0x32, 0x2c, 0x83
/* 4FE894 8021ECB4 4F838A81 */  .byte     0x4f, 0x83, 0x8a, 0x81
/* 4FE898 8021ECB8 5B839383 */  .byte     0x5b, 0x83, 0x93, 0x83
/* 4FE89C 8021ECBC 60838783 */  daddi     $v1, $a0, -0x787d
/* 4FE8A0 8021ECC0 8D837B83 */  lw        $v1, 0x7b83($t4)
/* 4FE8A4 8021ECC4 93000000 */  lbu       $zero, ($t8)
/* 4FE8A8 8021ECC8 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE8AC 8021ECCC 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE8B0 8021ECD0 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE8B4 8021ECD4 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE8B8 8021ECD8 2C834F83 */  sltiu     $v1, $a0, 0x4f83
/* 4FE8BC 8021ECDC 8A815B83 */  lwl       $at, 0x5b83($s4)
/* 4FE8C0 8021ECE0 93836083 */  lbu       $v1, 0x6083($gp)
/* 4FE8C4 8021ECE4 87838D83 */  lh        $v1, -0x727d($gp)
/* 4FE8C8 8021ECE8 7B839300 */  xori.b    $w12, $w18, 0x83
/* 4FE8CC 8021ECEC 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE8D0 8021ECF0 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE8D4 8021ECF4 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE8D8 8021ECF8 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE8DC 8021ECFC 78340000 */  andi.b    $w0, $w0, 0x34
/* 4FE8E0 8021ED00 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE8E4 8021ED04 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE8E8 8021ED08 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE8EC 8021ED0C 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE8F0 8021ED10 78330000 */  andi.b    $w0, $w0, 0x33
/* 4FE8F4 8021ED14 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE8F8 8021ED18 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE8FC 8021ED1C 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE900 8021ED20 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE904 8021ED24 78320000 */  andi.b    $w0, $w0, 0x32
/* 4FE908 8021ED28 83708362 */  lb        $s0, -0x7c9e($k1)
/* 4FE90C 8021ED2C 834E8393 */  lb        $t6, -0x7c6d($k0)
/* 4FE910 8021ED30 83748389 */  lb        $s4, -0x7c77($k1)
/* 4FE914 8021ED34 838F815B */  lb        $t7, -0x7ea5($gp)
/* 4FE918 8021ED38 00000000 */  nop       
/* 4FE91C 8021ED3C 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FE920 8021ED40 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FE924 8021ED44 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FE928 8021ED48 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FE92C 8021ED4C 83932C83 */  lb        $s3, 0x2c83($gp)
/* 4FE930 8021ED50 70836283 */  .byte     0x70, 0x83, 0x62, 0x83
/* 4FE934 8021ED54 4E839383 */  .byte     0x4e, 0x83, 0x93, 0x83
/* 4FE938 8021ED58 74838983 */  jalx      0x820e260c
/* 4FE93C 8021ED5C 8F815B2C */   lw       $at, 0x5b2c($gp)
/* 4FE940 8021ED60 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FE944 8021ED64 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FE948 8021ED68 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FE94C 8021ED6C 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FE950 8021ED70 83932C83 */  lb        $s3, 0x2c83($gp)
/* 4FE954 8021ED74 70836283 */  .byte     0x70, 0x83, 0x62, 0x83
/* 4FE958 8021ED78 4E839383 */  .byte     0x4e, 0x83, 0x93, 0x83
/* 4FE95C 8021ED7C 74838983 */  jalx      0x820e260c
/* 4FE960 8021ED80 8F815B00 */   lw       $at, 0x5b00($gp)
/* 4FE964 8021ED84 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FE968 8021ED88 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FE96C 8021ED8C 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FE970 8021ED90 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FE974 8021ED94 83937833 */  lb        $s3, 0x7833($gp)
/* 4FE978 8021ED98 2C837083 */  sltiu     $v1, $a0, 0x7083
/* 4FE97C 8021ED9C 62834E83 */  daddi     $v1, $s4, 0x4e83
/* 4FE980 8021EDA0 93837483 */  lbu       $v1, 0x7483($gp)
/* 4FE984 8021EDA4 89838F81 */  lwl       $v1, -0x707f($t4)
/* 4FE988 8021EDA8 5B000000 */  blezl     $t8, .L8021EDAC
.L8021EDAC:
/* 4FE98C 8021EDAC 834F838A */   lb       $t7, -0x7c76($k0)
/* 4FE990 8021EDB0 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FE994 8021EDB4 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FE998 8021EDB8 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FE99C 8021EDBC 83937832 */  lb        $s3, 0x7832($gp)
/* 4FE9A0 8021EDC0 2C837083 */  sltiu     $v1, $a0, 0x7083
/* 4FE9A4 8021EDC4 62834E83 */  daddi     $v1, $s4, 0x4e83
/* 4FE9A8 8021EDC8 93837483 */  lbu       $v1, 0x7483($gp)
/* 4FE9AC 8021EDCC 89838F81 */  lwl       $v1, -0x707f($t4)
/* 4FE9B0 8021EDD0 5B783200 */  .byte     0x5b, 0x78, 0x32, 0x00
/* 4FE9B4 8021EDD4 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FE9B8 8021EDD8 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FE9BC 8021EDDC 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FE9C0 8021EDE0 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FE9C4 8021EDE4 83937832 */  lb        $s3, 0x7832($gp)
/* 4FE9C8 8021EDE8 2C837083 */  sltiu     $v1, $a0, 0x7083
/* 4FE9CC 8021EDEC 62834E83 */  daddi     $v1, $s4, 0x4e83
/* 4FE9D0 8021EDF0 93837483 */  lbu       $v1, 0x7483($gp)
/* 4FE9D4 8021EDF4 89838F81 */  lwl       $v1, -0x707f($t4)
/* 4FE9D8 8021EDF8 5B000000 */  blezl     $t8, .L8021EDFC
.L8021EDFC:
/* 4FE9DC 8021EDFC 834F838A */   lb       $t7, -0x7c76($k0)
/* 4FE9E0 8021EE00 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FE9E4 8021EE04 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FE9E8 8021EE08 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FE9EC 8021EE0C 83932C83 */  lb        $s3, 0x2c83($gp)
/* 4FE9F0 8021EE10 70836283 */  .byte     0x70, 0x83, 0x62, 0x83
/* 4FE9F4 8021EE14 4E839383 */  .byte     0x4e, 0x83, 0x93, 0x83
/* 4FE9F8 8021EE18 74838983 */  jalx      0x820e260c
/* 4FE9FC 8021EE1C 8F815B00 */   lw       $at, 0x5b00($gp)
/* 4FEA00 8021EE20 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FEA04 8021EE24 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FEA08 8021EE28 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FEA0C 8021EE2C 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FEA10 8021EE30 83937834 */  lb        $s3, 0x7834($gp)
/* 4FEA14 8021EE34 00000000 */  nop       
/* 4FEA18 8021EE38 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FEA1C 8021EE3C 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FEA20 8021EE40 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FEA24 8021EE44 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FEA28 8021EE48 83937833 */  lb        $s3, 0x7833($gp)
/* 4FEA2C 8021EE4C 00000000 */  nop       
/* 4FEA30 8021EE50 834F838A */  lb        $t7, -0x7c76($k0)
/* 4FEA34 8021EE54 815B8393 */  lb        $k1, -0x7c6d($t2)
/* 4FEA38 8021EE58 83608387 */  lb        $zero, -0x7c79($k1)
/* 4FEA3C 8021EE5C 838D837B */  lb        $t5, -0x7c85($gp)
/* 4FEA40 8021EE60 83937832 */  lb        $s3, 0x7832($gp)
/* 4FEA44 8021EE64 00000000 */  nop       
/* 4FEA48 8021EE68 6D696D5F */  ldr       $t1, 0x6d5f($t3)
/* 4FEA4C 8021EE6C 30310000 */  andi      $s1, $at, 0
