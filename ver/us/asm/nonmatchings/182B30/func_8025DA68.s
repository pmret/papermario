.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025DA68
/* 18C348 8025DA68 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 18C34C 8025DA6C AFB1001C */  sw        $s1, 0x1c($sp)
/* 18C350 8025DA70 00A0882D */  daddu     $s1, $a1, $zero
/* 18C354 8025DA74 AFBF0020 */  sw        $ra, 0x20($sp)
/* 18C358 8025DA78 AFB00018 */  sw        $s0, 0x18($sp)
/* 18C35C 8025DA7C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 18C360 8025DA80 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 18C364 8025DA84 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 18C368 8025DA88 8C9000C0 */  lw        $s0, 0xc0($a0)
/* 18C36C 8025DA8C 00111100 */  sll       $v0, $s1, 4
/* 18C370 8025DA90 02021021 */  addu      $v0, $s0, $v0
/* 18C374 8025DA94 844208C6 */  lh        $v0, 0x8c6($v0)
/* 18C378 8025DA98 00021040 */  sll       $v0, $v0, 1
/* 18C37C 8025DA9C 3C018028 */  lui       $at, %hi(D_80284134)
/* 18C380 8025DAA0 00220821 */  addu      $at, $at, $v0
/* 18C384 8025DAA4 84224134 */  lh        $v0, %lo(D_80284134)($at)
/* 18C388 8025DAA8 0440003F */  bltz      $v0, .L8025DBA8
/* 18C38C 8025DAAC 02112821 */   addu     $a1, $s0, $s1
/* 18C390 8025DAB0 80A308BC */  lb        $v1, 0x8bc($a1)
/* 18C394 8025DAB4 10600005 */  beqz      $v1, .L8025DACC
/* 18C398 8025DAB8 24020001 */   addiu    $v0, $zero, 1
/* 18C39C 8025DABC 10620008 */  beq       $v1, $v0, .L8025DAE0
/* 18C3A0 8025DAC0 00000000 */   nop
/* 18C3A4 8025DAC4 080976EA */  j         .L8025DBA8
/* 18C3A8 8025DAC8 00000000 */   nop
.L8025DACC:
/* 18C3AC 8025DACC 00111040 */  sll       $v0, $s1, 1
/* 18C3B0 8025DAD0 02021021 */  addu      $v0, $s0, $v0
/* 18C3B4 8025DAD4 A44008BE */  sh        $zero, 0x8be($v0)
/* 18C3B8 8025DAD8 24020001 */  addiu     $v0, $zero, 1
/* 18C3BC 8025DADC A0A208BC */  sb        $v0, 0x8bc($a1)
.L8025DAE0:
/* 18C3C0 8025DAE0 90820073 */  lbu       $v0, 0x73($a0)
/* 18C3C4 8025DAE4 C482005C */  lwc1      $f2, 0x5c($a0)
/* 18C3C8 8025DAE8 C4940058 */  lwc1      $f20, 0x58($a0)
/* 18C3CC 8025DAEC 00021042 */  srl       $v0, $v0, 1
/* 18C3D0 8025DAF0 44820000 */  mtc1      $v0, $f0
/* 18C3D4 8025DAF4 00000000 */  nop
/* 18C3D8 8025DAF8 46800020 */  cvt.s.w   $f0, $f0
/* 18C3DC 8025DAFC 46001600 */  add.s     $f24, $f2, $f0
/* 18C3E0 8025DB00 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 18C3E4 8025DB04 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 18C3E8 8025DB08 C4820060 */  lwc1      $f2, 0x60($a0)
/* 18C3EC 8025DB0C 3C0140A0 */  lui       $at, 0x40a0
/* 18C3F0 8025DB10 44810000 */  mtc1      $at, $f0
/* 18C3F4 8025DB14 94420134 */  lhu       $v0, 0x134($v0)
/* 18C3F8 8025DB18 00021082 */  srl       $v0, $v0, 2
/* 18C3FC 8025DB1C 14400009 */  bnez      $v0, .L8025DB44
/* 18C400 8025DB20 46001581 */   sub.s    $f22, $f2, $f0
/* 18C404 8025DB24 4405A000 */  mfc1      $a1, $f20
/* 18C408 8025DB28 4406C000 */  mfc1      $a2, $f24
/* 18C40C 8025DB2C 4407B000 */  mfc1      $a3, $f22
/* 18C410 8025DB30 3C014120 */  lui       $at, 0x4120
/* 18C414 8025DB34 44810000 */  mtc1      $at, $f0
/* 18C418 8025DB38 24040001 */  addiu     $a0, $zero, 1
/* 18C41C 8025DB3C 0C01BFBC */  jal       playFX_11
/* 18C420 8025DB40 E7A00010 */   swc1     $f0, 0x10($sp)
.L8025DB44:
/* 18C424 8025DB44 00111040 */  sll       $v0, $s1, 1
/* 18C428 8025DB48 02024021 */  addu      $t0, $s0, $v0
/* 18C42C 8025DB4C 00111100 */  sll       $v0, $s1, 4
/* 18C430 8025DB50 950308BE */  lhu       $v1, 0x8be($t0)
/* 18C434 8025DB54 02021021 */  addu      $v0, $s0, $v0
/* 18C438 8025DB58 24630001 */  addiu     $v1, $v1, 1
/* 18C43C 8025DB5C A50308BE */  sh        $v1, 0x8be($t0)
/* 18C440 8025DB60 844208C6 */  lh        $v0, 0x8c6($v0)
/* 18C444 8025DB64 00031C00 */  sll       $v1, $v1, 0x10
/* 18C448 8025DB68 00021040 */  sll       $v0, $v0, 1
/* 18C44C 8025DB6C 3C018028 */  lui       $at, %hi(D_80284134)
/* 18C450 8025DB70 00220821 */  addu      $at, $at, $v0
/* 18C454 8025DB74 84224134 */  lh        $v0, %lo(D_80284134)($at)
/* 18C458 8025DB78 00031C03 */  sra       $v1, $v1, 0x10
/* 18C45C 8025DB7C 0043102A */  slt       $v0, $v0, $v1
/* 18C460 8025DB80 10400009 */  beqz      $v0, .L8025DBA8
/* 18C464 8025DB84 24040001 */   addiu    $a0, $zero, 1
/* 18C468 8025DB88 4405A000 */  mfc1      $a1, $f20
/* 18C46C 8025DB8C 4406C000 */  mfc1      $a2, $f24
/* 18C470 8025DB90 4407B000 */  mfc1      $a3, $f22
/* 18C474 8025DB94 3C0141A0 */  lui       $at, 0x41a0
/* 18C478 8025DB98 44810000 */  mtc1      $at, $f0
/* 18C47C 8025DB9C A50008BE */  sh        $zero, 0x8be($t0)
/* 18C480 8025DBA0 0C01BFBC */  jal       playFX_11
/* 18C484 8025DBA4 E7A00010 */   swc1     $f0, 0x10($sp)
.L8025DBA8:
/* 18C488 8025DBA8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 18C48C 8025DBAC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18C490 8025DBB0 8FB00018 */  lw        $s0, 0x18($sp)
/* 18C494 8025DBB4 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 18C498 8025DBB8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 18C49C 8025DBBC D7B40028 */  ldc1      $f20, 0x28($sp)
/* 18C4A0 8025DBC0 03E00008 */  jr        $ra
/* 18C4A4 8025DBC4 27BD0040 */   addiu    $sp, $sp, 0x40
