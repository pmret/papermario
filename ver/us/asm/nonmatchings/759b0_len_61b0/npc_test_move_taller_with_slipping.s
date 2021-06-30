.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel npc_test_move_taller_with_slipping
/* 76F94 800DDAE4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 76F98 800DDAE8 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 76F9C 800DDAEC C7B40084 */  lwc1      $f20, 0x84($sp)
/* 76FA0 800DDAF0 C7A40078 */  lwc1      $f4, 0x78($sp)
/* 76FA4 800DDAF4 AFB60048 */  sw        $s6, 0x48($sp)
/* 76FA8 800DDAF8 0080B02D */  daddu     $s6, $a0, $zero
/* 76FAC 800DDAFC AFB3003C */  sw        $s3, 0x3c($sp)
/* 76FB0 800DDB00 00A0982D */  daddu     $s3, $a1, $zero
/* 76FB4 800DDB04 AFB50044 */  sw        $s5, 0x44($sp)
/* 76FB8 800DDB08 00C0A82D */  daddu     $s5, $a2, $zero
/* 76FBC 800DDB0C AFB40040 */  sw        $s4, 0x40($sp)
/* 76FC0 800DDB10 00E0A02D */  daddu     $s4, $a3, $zero
/* 76FC4 800DDB14 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 76FC8 800DDB18 C7B8007C */  lwc1      $f24, 0x7c($sp)
/* 76FCC 800DDB1C C7A20080 */  lwc1      $f2, 0x80($sp)
/* 76FD0 800DDB20 AFBF004C */  sw        $ra, 0x4c($sp)
/* 76FD4 800DDB24 AFB20038 */  sw        $s2, 0x38($sp)
/* 76FD8 800DDB28 AFB10034 */  sw        $s1, 0x34($sp)
/* 76FDC 800DDB2C AFB00030 */  sw        $s0, 0x30($sp)
/* 76FE0 800DDB30 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 76FE4 800DDB34 C6600000 */  lwc1      $f0, ($s3)
/* 76FE8 800DDB38 27B20020 */  addiu     $s2, $sp, 0x20
/* 76FEC 800DDB3C E7A00020 */  swc1      $f0, 0x20($sp)
/* 76FF0 800DDB40 C6A00000 */  lwc1      $f0, ($s5)
/* 76FF4 800DDB44 0240282D */  daddu     $a1, $s2, $zero
/* 76FF8 800DDB48 46020000 */  add.s     $f0, $f0, $f2
/* 76FFC 800DDB4C 3C013F80 */  lui       $at, 0x3f80
/* 77000 800DDB50 44811000 */  mtc1      $at, $f2
/* 77004 800DDB54 27B10024 */  addiu     $s1, $sp, 0x24
/* 77008 800DDB58 46020001 */  sub.s     $f0, $f0, $f2
/* 7700C 800DDB5C 3C013F00 */  lui       $at, 0x3f00
/* 77010 800DDB60 44811000 */  mtc1      $at, $f2
/* 77014 800DDB64 0220302D */  daddu     $a2, $s1, $zero
/* 77018 800DDB68 4602A502 */  mul.s     $f20, $f20, $f2
/* 7701C 800DDB6C 00000000 */  nop
/* 77020 800DDB70 27B00028 */  addiu     $s0, $sp, 0x28
/* 77024 800DDB74 0200382D */  daddu     $a3, $s0, $zero
/* 77028 800DDB78 E7A00024 */  swc1      $f0, 0x24($sp)
/* 7702C 800DDB7C C6800000 */  lwc1      $f0, ($s4)
/* 77030 800DDB80 46002585 */  abs.s     $f22, $f4
/* 77034 800DDB84 E7A00028 */  swc1      $f0, 0x28($sp)
/* 77038 800DDB88 E7B60010 */  swc1      $f22, 0x10($sp)
/* 7703C 800DDB8C E7B80014 */  swc1      $f24, 0x14($sp)
/* 77040 800DDB90 0C037586 */  jal       npc_test_move_with_slipping
/* 77044 800DDB94 E7B40018 */   swc1     $f20, 0x18($sp)
/* 77048 800DDB98 04430019 */  bgezl     $v0, .L800DDC00
/* 7704C 800DDB9C 24020001 */   addiu    $v0, $zero, 1
/* 77050 800DDBA0 C6600000 */  lwc1      $f0, ($s3)
/* 77054 800DDBA4 3C014120 */  lui       $at, 0x4120
/* 77058 800DDBA8 342128F6 */  ori       $at, $at, 0x28f6
/* 7705C 800DDBAC 44811000 */  mtc1      $at, $f2
/* 77060 800DDBB0 E7A00020 */  swc1      $f0, 0x20($sp)
/* 77064 800DDBB4 C6A00000 */  lwc1      $f0, ($s5)
/* 77068 800DDBB8 02C0202D */  daddu     $a0, $s6, $zero
/* 7706C 800DDBBC 46020000 */  add.s     $f0, $f0, $f2
/* 77070 800DDBC0 0240282D */  daddu     $a1, $s2, $zero
/* 77074 800DDBC4 0220302D */  daddu     $a2, $s1, $zero
/* 77078 800DDBC8 E7A00024 */  swc1      $f0, 0x24($sp)
/* 7707C 800DDBCC C6800000 */  lwc1      $f0, ($s4)
/* 77080 800DDBD0 0200382D */  daddu     $a3, $s0, $zero
/* 77084 800DDBD4 E7A00028 */  swc1      $f0, 0x28($sp)
/* 77088 800DDBD8 E7B60010 */  swc1      $f22, 0x10($sp)
/* 7708C 800DDBDC E7B80014 */  swc1      $f24, 0x14($sp)
/* 77090 800DDBE0 0C037586 */  jal       npc_test_move_with_slipping
/* 77094 800DDBE4 E7B40018 */   swc1     $f20, 0x18($sp)
/* 77098 800DDBE8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7709C 800DDBEC 00021027 */  nor       $v0, $zero, $v0
/* 770A0 800DDBF0 E6600000 */  swc1      $f0, ($s3)
/* 770A4 800DDBF4 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 770A8 800DDBF8 08037703 */  j         .L800DDC0C
/* 770AC 800DDBFC 000217C2 */   srl      $v0, $v0, 0x1f
.L800DDC00:
/* 770B0 800DDC00 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 770B4 800DDC04 E6600000 */  swc1      $f0, ($s3)
/* 770B8 800DDC08 C7A00028 */  lwc1      $f0, 0x28($sp)
.L800DDC0C:
/* 770BC 800DDC0C E6800000 */  swc1      $f0, ($s4)
/* 770C0 800DDC10 8FBF004C */  lw        $ra, 0x4c($sp)
/* 770C4 800DDC14 8FB60048 */  lw        $s6, 0x48($sp)
/* 770C8 800DDC18 8FB50044 */  lw        $s5, 0x44($sp)
/* 770CC 800DDC1C 8FB40040 */  lw        $s4, 0x40($sp)
/* 770D0 800DDC20 8FB3003C */  lw        $s3, 0x3c($sp)
/* 770D4 800DDC24 8FB20038 */  lw        $s2, 0x38($sp)
/* 770D8 800DDC28 8FB10034 */  lw        $s1, 0x34($sp)
/* 770DC 800DDC2C 8FB00030 */  lw        $s0, 0x30($sp)
/* 770E0 800DDC30 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 770E4 800DDC34 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 770E8 800DDC38 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 770EC 800DDC3C 03E00008 */  jr        $ra
/* 770F0 800DDC40 27BD0068 */   addiu    $sp, $sp, 0x68
