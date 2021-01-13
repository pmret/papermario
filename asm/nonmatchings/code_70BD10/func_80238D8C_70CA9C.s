.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238D8C_70CA9C
/* 70CA9C 80238D8C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 70CAA0 80238D90 AFB50024 */  sw        $s5, 0x24($sp)
/* 70CAA4 80238D94 3C15800E */  lui       $s5, %hi(gBattleStatus+0xDC)
/* 70CAA8 80238D98 8EB5C14C */  lw        $s5, %lo(gBattleStatus+0xDC)($s5)
/* 70CAAC 80238D9C AFBF0034 */  sw        $ra, 0x34($sp)
/* 70CAB0 80238DA0 AFBE0030 */  sw        $fp, 0x30($sp)
/* 70CAB4 80238DA4 AFB7002C */  sw        $s7, 0x2c($sp)
/* 70CAB8 80238DA8 AFB60028 */  sw        $s6, 0x28($sp)
/* 70CABC 80238DAC AFB40020 */  sw        $s4, 0x20($sp)
/* 70CAC0 80238DB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 70CAC4 80238DB4 AFB20018 */  sw        $s2, 0x18($sp)
/* 70CAC8 80238DB8 AFB10014 */  sw        $s1, 0x14($sp)
/* 70CACC 80238DBC AFB00010 */  sw        $s0, 0x10($sp)
/* 70CAD0 80238DC0 AFA40038 */  sw        $a0, 0x38($sp)
/* 70CAD4 80238DC4 3C018024 */  lui       $at, %hi(D_8023D330)
/* 70CAD8 80238DC8 AC20D330 */  sw        $zero, %lo(D_8023D330)($at)
/* 70CADC 80238DCC 3C018024 */  lui       $at, %hi(D_8023D334)
/* 70CAE0 80238DD0 AC20D334 */  sw        $zero, %lo(D_8023D334)($at)
/* 70CAE4 80238DD4 82A2040C */  lb        $v0, 0x40c($s5)
/* 70CAE8 80238DD8 18400009 */  blez      $v0, .L80238E00
/* 70CAEC 80238DDC 0000982D */   daddu    $s3, $zero, $zero
/* 70CAF0 80238DE0 3C038024 */  lui       $v1, %hi(D_8023D2D0)
/* 70CAF4 80238DE4 2463D2D0 */  addiu     $v1, $v1, %lo(D_8023D2D0)
.L80238DE8:
/* 70CAF8 80238DE8 AC600000 */  sw        $zero, ($v1)
/* 70CAFC 80238DEC 82A2040C */  lb        $v0, 0x40c($s5)
/* 70CB00 80238DF0 26730001 */  addiu     $s3, $s3, 1
/* 70CB04 80238DF4 0262102A */  slt       $v0, $s3, $v0
/* 70CB08 80238DF8 1440FFFB */  bnez      $v0, .L80238DE8
/* 70CB0C 80238DFC 24630004 */   addiu    $v1, $v1, 4
.L80238E00:
/* 70CB10 80238E00 0000B02D */  daddu     $s6, $zero, $zero
/* 70CB14 80238E04 02C0902D */  daddu     $s2, $s6, $zero
/* 70CB18 80238E08 82A2040C */  lb        $v0, 0x40c($s5)
/* 70CB1C 80238E0C 18400056 */  blez      $v0, .L80238F68
/* 70CB20 80238E10 02C0982D */   daddu    $s3, $s6, $zero
/* 70CB24 80238E14 3C1751EB */  lui       $s7, 0x51eb
/* 70CB28 80238E18 36F7851F */  ori       $s7, $s7, 0x851f
/* 70CB2C 80238E1C 3C1E8024 */  lui       $fp, %hi(D_8023D2D0)
/* 70CB30 80238E20 27DED2D0 */  addiu     $fp, $fp, %lo(D_8023D2D0)
.L80238E24:
/* 70CB34 80238E24 02B31021 */  addu      $v0, $s5, $s3
/* 70CB38 80238E28 8054040D */  lb        $s4, 0x40d($v0)
/* 70CB3C 80238E2C 00141080 */  sll       $v0, $s4, 2
/* 70CB40 80238E30 00541021 */  addu      $v0, $v0, $s4
/* 70CB44 80238E34 00021080 */  sll       $v0, $v0, 2
/* 70CB48 80238E38 2442022C */  addiu     $v0, $v0, 0x22c
/* 70CB4C 80238E3C 02A28021 */  addu      $s0, $s5, $v0
/* 70CB50 80238E40 0C09A75B */  jal       get_actor
/* 70CB54 80238E44 86040000 */   lh       $a0, ($s0)
/* 70CB58 80238E48 0040882D */  daddu     $s1, $v0, $zero
/* 70CB5C 80238E4C 86050002 */  lh        $a1, 2($s0)
/* 70CB60 80238E50 0C099117 */  jal       get_actor_part
/* 70CB64 80238E54 0220202D */   daddu    $a0, $s1, $zero
/* 70CB68 80238E58 822401B8 */  lb        $a0, 0x1b8($s1)
/* 70CB6C 80238E5C 00041840 */  sll       $v1, $a0, 1
/* 70CB70 80238E60 00641821 */  addu      $v1, $v1, $a0
/* 70CB74 80238E64 000318C0 */  sll       $v1, $v1, 3
/* 70CB78 80238E68 00641821 */  addu      $v1, $v1, $a0
/* 70CB7C 80238E6C 822401B9 */  lb        $a0, 0x1b9($s1)
/* 70CB80 80238E70 00031880 */  sll       $v1, $v1, 2
/* 70CB84 80238E74 14800002 */  bnez      $a0, .L80238E80
/* 70CB88 80238E78 0064001A */   div      $zero, $v1, $a0
/* 70CB8C 80238E7C 0007000D */  break     7
.L80238E80:
/* 70CB90 80238E80 2401FFFF */   addiu    $at, $zero, -1
/* 70CB94 80238E84 14810004 */  bne       $a0, $at, .L80238E98
/* 70CB98 80238E88 3C018000 */   lui      $at, 0x8000
/* 70CB9C 80238E8C 14610002 */  bne       $v1, $at, .L80238E98
/* 70CBA0 80238E90 00000000 */   nop
/* 70CBA4 80238E94 0006000D */  break     6
.L80238E98:
/* 70CBA8 80238E98 00001812 */   mflo     $v1
/* 70CBAC 80238E9C 0040282D */  daddu     $a1, $v0, $zero
/* 70CBB0 80238EA0 8E240008 */  lw        $a0, 8($s1)
/* 70CBB4 80238EA4 24020064 */  addiu     $v0, $zero, 0x64
/* 70CBB8 80238EA8 9084001A */  lbu       $a0, 0x1a($a0)
/* 70CBBC 80238EAC 18800026 */  blez      $a0, .L80238F48
/* 70CBC0 80238EB0 00431023 */   subu     $v0, $v0, $v1
/* 70CBC4 80238EB4 00820018 */  mult      $a0, $v0
/* 70CBC8 80238EB8 00001812 */  mflo      $v1
/* 70CBCC 80238EBC 00000000 */  nop
/* 70CBD0 80238EC0 00000000 */  nop
/* 70CBD4 80238EC4 00770018 */  mult      $v1, $s7
/* 70CBD8 80238EC8 00031FC3 */  sra       $v1, $v1, 0x1f
/* 70CBDC 80238ECC 00003810 */  mfhi      $a3
/* 70CBE0 80238ED0 00071143 */  sra       $v0, $a3, 5
/* 70CBE4 80238ED4 00431023 */  subu      $v0, $v0, $v1
/* 70CBE8 80238ED8 00822021 */  addu      $a0, $a0, $v0
/* 70CBEC 80238EDC 28820065 */  slti      $v0, $a0, 0x65
/* 70CBF0 80238EE0 50400001 */  beql      $v0, $zero, .L80238EE8
/* 70CBF4 80238EE4 24040064 */   addiu    $a0, $zero, 0x64
.L80238EE8:
/* 70CBF8 80238EE8 82220210 */  lb        $v0, 0x210($s1)
/* 70CBFC 80238EEC 1040000D */  beqz      $v0, .L80238F24
/* 70CC00 80238EF0 00041880 */   sll      $v1, $a0, 2
/* 70CC04 80238EF4 00641821 */  addu      $v1, $v1, $a0
/* 70CC08 80238EF8 00031100 */  sll       $v0, $v1, 4
/* 70CC0C 80238EFC 00431023 */  subu      $v0, $v0, $v1
/* 70CC10 80238F00 00021040 */  sll       $v0, $v0, 1
/* 70CC14 80238F04 00570018 */  mult      $v0, $s7
/* 70CC18 80238F08 000217C3 */  sra       $v0, $v0, 0x1f
/* 70CC1C 80238F0C 00003010 */  mfhi      $a2
/* 70CC20 80238F10 00061943 */  sra       $v1, $a2, 5
/* 70CC24 80238F14 00622023 */  subu      $a0, $v1, $v0
/* 70CC28 80238F18 28820097 */  slti      $v0, $a0, 0x97
/* 70CC2C 80238F1C 50400001 */  beql      $v0, $zero, .L80238F24
/* 70CC30 80238F20 24040096 */   addiu    $a0, $zero, 0x96
.L80238F24:
/* 70CC34 80238F24 82230218 */  lb        $v1, 0x218($s1)
/* 70CC38 80238F28 2402000E */  addiu     $v0, $zero, 0xe
/* 70CC3C 80238F2C 50620001 */  beql      $v1, $v0, .L80238F34
/* 70CC40 80238F30 0000202D */   daddu    $a0, $zero, $zero
.L80238F34:
/* 70CC44 80238F34 8CA2007C */  lw        $v0, 0x7c($a1)
/* 70CC48 80238F38 30420020 */  andi      $v0, $v0, 0x20
/* 70CC4C 80238F3C 54400001 */  bnel      $v0, $zero, .L80238F44
/* 70CC50 80238F40 0000202D */   daddu    $a0, $zero, $zero
.L80238F44:
/* 70CC54 80238F44 26520001 */  addiu     $s2, $s2, 1
.L80238F48:
/* 70CC58 80238F48 00141080 */  sll       $v0, $s4, 2
/* 70CC5C 80238F4C 005E1021 */  addu      $v0, $v0, $fp
/* 70CC60 80238F50 AC440000 */  sw        $a0, ($v0)
/* 70CC64 80238F54 82A2040C */  lb        $v0, 0x40c($s5)
/* 70CC68 80238F58 26730001 */  addiu     $s3, $s3, 1
/* 70CC6C 80238F5C 0262102A */  slt       $v0, $s3, $v0
/* 70CC70 80238F60 1440FFB0 */  bnez      $v0, .L80238E24
/* 70CC74 80238F64 02C4B021 */   addu     $s6, $s6, $a0
.L80238F68:
/* 70CC78 80238F68 5240000B */  beql      $s2, $zero, .L80238F98
/* 70CC7C 80238F6C 0000B02D */   daddu    $s6, $zero, $zero
/* 70CC80 80238F70 16400002 */  bnez      $s2, .L80238F7C
/* 70CC84 80238F74 02D2001A */   div      $zero, $s6, $s2
/* 70CC88 80238F78 0007000D */  break     7
.L80238F7C:
/* 70CC8C 80238F7C 2401FFFF */   addiu    $at, $zero, -1
/* 70CC90 80238F80 16410004 */  bne       $s2, $at, .L80238F94
/* 70CC94 80238F84 3C018000 */   lui      $at, 0x8000
/* 70CC98 80238F88 16C10002 */  bne       $s6, $at, .L80238F94
/* 70CC9C 80238F8C 00000000 */   nop
/* 70CCA0 80238F90 0006000D */  break     6
.L80238F94:
/* 70CCA4 80238F94 0000B012 */   mflo     $s6
.L80238F98:
/* 70CCA8 80238F98 8FA60038 */  lw        $a2, 0x38($sp)
/* 70CCAC 80238F9C ACD60084 */  sw        $s6, 0x84($a2)
/* 70CCB0 80238FA0 82A2040C */  lb        $v0, 0x40c($s5)
/* 70CCB4 80238FA4 18400024 */  blez      $v0, .L80239038
/* 70CCB8 80238FA8 0000982D */   daddu    $s3, $zero, $zero
/* 70CCBC 80238FAC 3C178024 */  lui       $s7, %hi(D_8023D2D0)
/* 70CCC0 80238FB0 26F7D2D0 */  addiu     $s7, $s7, %lo(D_8023D2D0)
/* 70CCC4 80238FB4 241EFFFF */  addiu     $fp, $zero, -1
/* 70CCC8 80238FB8 02B31021 */  addu      $v0, $s5, $s3
.L80238FBC:
/* 70CCCC 80238FBC 8054040D */  lb        $s4, 0x40d($v0)
/* 70CCD0 80238FC0 00149080 */  sll       $s2, $s4, 2
/* 70CCD4 80238FC4 02541021 */  addu      $v0, $s2, $s4
/* 70CCD8 80238FC8 00021080 */  sll       $v0, $v0, 2
/* 70CCDC 80238FCC 2442022C */  addiu     $v0, $v0, 0x22c
/* 70CCE0 80238FD0 02A28021 */  addu      $s0, $s5, $v0
/* 70CCE4 80238FD4 0C09A75B */  jal       get_actor
/* 70CCE8 80238FD8 86040000 */   lh       $a0, ($s0)
/* 70CCEC 80238FDC 0040882D */  daddu     $s1, $v0, $zero
/* 70CCF0 80238FE0 86050002 */  lh        $a1, 2($s0)
/* 70CCF4 80238FE4 0C099117 */  jal       get_actor_part
/* 70CCF8 80238FE8 0220202D */   daddu    $a0, $s1, $zero
/* 70CCFC 80238FEC 82230218 */  lb        $v1, 0x218($s1)
/* 70CD00 80238FF0 2406000E */  addiu     $a2, $zero, 0xe
/* 70CD04 80238FF4 10660005 */  beq       $v1, $a2, .L8023900C
/* 70CD08 80238FF8 0040282D */   daddu    $a1, $v0, $zero
/* 70CD0C 80238FFC 8CA2007C */  lw        $v0, 0x7c($a1)
/* 70CD10 80239000 30420020 */  andi      $v0, $v0, 0x20
/* 70CD14 80239004 10400004 */  beqz      $v0, .L80239018
/* 70CD18 80239008 02571821 */   addu     $v1, $s2, $s7
.L8023900C:
/* 70CD1C 8023900C 02571021 */  addu      $v0, $s2, $s7
/* 70CD20 80239010 0808E409 */  j         .L80239024
/* 70CD24 80239014 AC5E0000 */   sw       $fp, ($v0)
.L80239018:
/* 70CD28 80239018 8C620000 */  lw        $v0, ($v1)
/* 70CD2C 8023901C 54400001 */  bnel      $v0, $zero, .L80239024
/* 70CD30 80239020 AC760000 */   sw       $s6, ($v1)
.L80239024:
/* 70CD34 80239024 82A2040C */  lb        $v0, 0x40c($s5)
/* 70CD38 80239028 26730001 */  addiu     $s3, $s3, 1
/* 70CD3C 8023902C 0262102A */  slt       $v0, $s3, $v0
/* 70CD40 80239030 1440FFE2 */  bnez      $v0, .L80238FBC
/* 70CD44 80239034 02B31021 */   addu     $v0, $s5, $s3
.L80239038:
/* 70CD48 80239038 8FBF0034 */  lw        $ra, 0x34($sp)
/* 70CD4C 8023903C 8FBE0030 */  lw        $fp, 0x30($sp)
/* 70CD50 80239040 8FB7002C */  lw        $s7, 0x2c($sp)
/* 70CD54 80239044 8FB60028 */  lw        $s6, 0x28($sp)
/* 70CD58 80239048 8FB50024 */  lw        $s5, 0x24($sp)
/* 70CD5C 8023904C 8FB40020 */  lw        $s4, 0x20($sp)
/* 70CD60 80239050 8FB3001C */  lw        $s3, 0x1c($sp)
/* 70CD64 80239054 8FB20018 */  lw        $s2, 0x18($sp)
/* 70CD68 80239058 8FB10014 */  lw        $s1, 0x14($sp)
/* 70CD6C 8023905C 8FB00010 */  lw        $s0, 0x10($sp)
/* 70CD70 80239060 24020002 */  addiu     $v0, $zero, 2
/* 70CD74 80239064 03E00008 */  jr        $ra
/* 70CD78 80239068 27BD0038 */   addiu    $sp, $sp, 0x38
