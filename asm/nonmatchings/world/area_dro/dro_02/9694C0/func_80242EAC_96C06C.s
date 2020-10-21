.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EAC_96C06C
/* 96C06C 80242EAC 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 96C070 80242EB0 3C05F4AC */  lui       $a1, 0xf4ac
/* 96C074 80242EB4 AFB20068 */  sw        $s2, 0x68($sp)
/* 96C078 80242EB8 3C128025 */  lui       $s2, 0x8025
/* 96C07C 80242EBC 2652EFCC */  addiu     $s2, $s2, -0x1034
/* 96C080 80242EC0 AFBF006C */  sw        $ra, 0x6c($sp)
/* 96C084 80242EC4 AFB10064 */  sw        $s1, 0x64($sp)
/* 96C088 80242EC8 AFB00060 */  sw        $s0, 0x60($sp)
/* 96C08C 80242ECC F7B60078 */  sdc1      $f22, 0x78($sp)
/* 96C090 80242ED0 F7B40070 */  sdc1      $f20, 0x70($sp)
/* 96C094 80242ED4 8E440000 */  lw        $a0, ($s2)
/* 96C098 80242ED8 0C0B1EAF */  jal       get_variable
/* 96C09C 80242EDC 34A5D484 */   ori      $a1, $a1, 0xd484
/* 96C0A0 80242EE0 3C05F4AC */  lui       $a1, 0xf4ac
/* 96C0A4 80242EE4 8E440000 */  lw        $a0, ($s2)
/* 96C0A8 80242EE8 4482B000 */  mtc1      $v0, $f22
/* 96C0AC 80242EEC 00000000 */  nop       
/* 96C0B0 80242EF0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 96C0B4 80242EF4 0C0B1EAF */  jal       get_variable
/* 96C0B8 80242EF8 34A5D485 */   ori      $a1, $a1, 0xd485
/* 96C0BC 80242EFC 3C05F4AC */  lui       $a1, 0xf4ac
/* 96C0C0 80242F00 8E440000 */  lw        $a0, ($s2)
/* 96C0C4 80242F04 4482A000 */  mtc1      $v0, $f20
/* 96C0C8 80242F08 00000000 */  nop       
/* 96C0CC 80242F0C 4680A520 */  cvt.s.w   $f20, $f20
/* 96C0D0 80242F10 0C0B1EAF */  jal       get_variable
/* 96C0D4 80242F14 34A5D486 */   ori      $a1, $a1, 0xd486
/* 96C0D8 80242F18 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 96C0DC 80242F1C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 96C0E0 80242F20 44800000 */  mtc1      $zero, $f0
/* 96C0E4 80242F24 00041880 */  sll       $v1, $a0, 2
/* 96C0E8 80242F28 00641821 */  addu      $v1, $v1, $a0
/* 96C0EC 80242F2C 00031880 */  sll       $v1, $v1, 2
/* 96C0F0 80242F30 00641823 */  subu      $v1, $v1, $a0
/* 96C0F4 80242F34 000320C0 */  sll       $a0, $v1, 3
/* 96C0F8 80242F38 00641821 */  addu      $v1, $v1, $a0
/* 96C0FC 80242F3C 000318C0 */  sll       $v1, $v1, 3
/* 96C100 80242F40 44050000 */  mfc1      $a1, $f0
/* 96C104 80242F44 3C01800B */  lui       $at, 0x800b
/* 96C108 80242F48 00230821 */  addu      $at, $at, $v1
/* 96C10C 80242F4C C4221DEC */  lwc1      $f2, 0x1dec($at)
/* 96C110 80242F50 3C013F36 */  lui       $at, 0x3f36
/* 96C114 80242F54 3421DB6E */  ori       $at, $at, 0xdb6e
/* 96C118 80242F58 44810000 */  mtc1      $at, $f0
/* 96C11C 80242F5C 27A40020 */  addiu     $a0, $sp, 0x20
/* 96C120 80242F60 E7B60014 */  swc1      $f22, 0x14($sp)
/* 96C124 80242F64 E7B40018 */  swc1      $f20, 0x18($sp)
/* 96C128 80242F68 E7A00010 */  swc1      $f0, 0x10($sp)
/* 96C12C 80242F6C 44820000 */  mtc1      $v0, $f0
/* 96C130 80242F70 00000000 */  nop       
/* 96C134 80242F74 46800020 */  cvt.s.w   $f0, $f0
/* 96C138 80242F78 46001087 */  neg.s     $f2, $f2
/* 96C13C 80242F7C 44061000 */  mfc1      $a2, $f2
/* 96C140 80242F80 00A0382D */  daddu     $a3, $a1, $zero
/* 96C144 80242F84 0C018FC4 */  jal       guPositionF
/* 96C148 80242F88 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 96C14C 80242F8C 3C108025 */  lui       $s0, 0x8025
/* 96C150 80242F90 2610F010 */  addiu     $s0, $s0, -0xff0
/* 96C154 80242F94 0200202D */  daddu     $a0, $s0, $zero
/* 96C158 80242F98 0C090643 */  jal       func_8024190C_96AACC
/* 96C15C 80242F9C 27A50020 */   addiu    $a1, $sp, 0x20
/* 96C160 80242FA0 26040024 */  addiu     $a0, $s0, 0x24
/* 96C164 80242FA4 27A50020 */  addiu     $a1, $sp, 0x20
/* 96C168 80242FA8 0C090643 */  jal       func_8024190C_96AACC
/* 96C16C 80242FAC 0040882D */   daddu    $s1, $v0, $zero
/* 96C170 80242FB0 26040048 */  addiu     $a0, $s0, 0x48
/* 96C174 80242FB4 0C090643 */  jal       func_8024190C_96AACC
/* 96C178 80242FB8 27A50020 */   addiu    $a1, $sp, 0x20
/* 96C17C 80242FBC 8E030000 */  lw        $v1, ($s0)
/* 96C180 80242FC0 24020002 */  addiu     $v0, $zero, 2
/* 96C184 80242FC4 14620008 */  bne       $v1, $v0, .L80242FE8
/* 96C188 80242FC8 2622FFFF */   addiu    $v0, $s1, -1
/* 96C18C 80242FCC 2C420002 */  sltiu     $v0, $v0, 2
/* 96C190 80242FD0 10400005 */  beqz      $v0, .L80242FE8
/* 96C194 80242FD4 3C05F4AC */   lui      $a1, 0xf4ac
/* 96C198 80242FD8 8E440000 */  lw        $a0, ($s2)
/* 96C19C 80242FDC 34A5D489 */  ori       $a1, $a1, 0xd489
/* 96C1A0 80242FE0 0C0B2026 */  jal       set_variable
/* 96C1A4 80242FE4 24060003 */   addiu    $a2, $zero, 3
.L80242FE8:
/* 96C1A8 80242FE8 3C038025 */  lui       $v1, 0x8025
/* 96C1AC 80242FEC 8C63F010 */  lw        $v1, -0xff0($v1)
/* 96C1B0 80242FF0 24020003 */  addiu     $v0, $zero, 3
/* 96C1B4 80242FF4 14620009 */  bne       $v1, $v0, .L8024301C
/* 96C1B8 80242FF8 2622FFFF */   addiu    $v0, $s1, -1
/* 96C1BC 80242FFC 2C420002 */  sltiu     $v0, $v0, 2
/* 96C1C0 80243000 10400006 */  beqz      $v0, .L8024301C
/* 96C1C4 80243004 3C05F4AC */   lui      $a1, 0xf4ac
/* 96C1C8 80243008 3C048025 */  lui       $a0, 0x8025
/* 96C1CC 8024300C 8C84EFCC */  lw        $a0, -0x1034($a0)
/* 96C1D0 80243010 34A5D489 */  ori       $a1, $a1, 0xd489
/* 96C1D4 80243014 0C0B2026 */  jal       set_variable
/* 96C1D8 80243018 2406000B */   addiu    $a2, $zero, 0xb
.L8024301C:
/* 96C1DC 8024301C 8FBF006C */  lw        $ra, 0x6c($sp)
/* 96C1E0 80243020 8FB20068 */  lw        $s2, 0x68($sp)
/* 96C1E4 80243024 8FB10064 */  lw        $s1, 0x64($sp)
/* 96C1E8 80243028 8FB00060 */  lw        $s0, 0x60($sp)
/* 96C1EC 8024302C D7B60078 */  ldc1      $f22, 0x78($sp)
/* 96C1F0 80243030 D7B40070 */  ldc1      $f20, 0x70($sp)
/* 96C1F4 80243034 03E00008 */  jr        $ra
/* 96C1F8 80243038 27BD0080 */   addiu    $sp, $sp, 0x80
