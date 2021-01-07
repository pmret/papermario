.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D04
/* 136044 80242D04 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 136048 80242D08 AFB20018 */  sw        $s2, 0x18($sp)
/* 13604C 80242D0C 00A0902D */  daddu     $s2, $a1, $zero
/* 136050 80242D10 AFB3001C */  sw        $s3, 0x1c($sp)
/* 136054 80242D14 00C0982D */  daddu     $s3, $a2, $zero
/* 136058 80242D18 AFB40020 */  sw        $s4, 0x20($sp)
/* 13605C 80242D1C 3C148016 */  lui       $s4, %hi(gUIPanels)
/* 136060 80242D20 26949D50 */  addiu     $s4, $s4, %lo(gUIPanels)
/* 136064 80242D24 00042140 */  sll       $a0, $a0, 5
/* 136068 80242D28 AFB10014 */  sw        $s1, 0x14($sp)
/* 13606C 80242D2C 3C118025 */  lui       $s1, %hi(D_8024EFB4)
/* 136070 80242D30 2631EFB4 */  addiu     $s1, $s1, %lo(D_8024EFB4)
/* 136074 80242D34 AFBF0024 */  sw        $ra, 0x24($sp)
/* 136078 80242D38 AFB00010 */  sw        $s0, 0x10($sp)
/* 13607C 80242D3C 8E220000 */  lw        $v0, ($s1)
/* 136080 80242D40 14400012 */  bnez      $v0, .L80242D8C
/* 136084 80242D44 00948021 */   addu     $s0, $a0, $s4
/* 136088 80242D48 0C00CD4A */  jal       get_game_mode
/* 13608C 80242D4C 00000000 */   nop      
/* 136090 80242D50 00021400 */  sll       $v0, $v0, 0x10
/* 136094 80242D54 00021403 */  sra       $v0, $v0, 0x10
/* 136098 80242D58 2403000F */  addiu     $v1, $zero, 0xf
/* 13609C 80242D5C 10430008 */  beq       $v0, $v1, .L80242D80
/* 1360A0 80242D60 00000000 */   nop      
/* 1360A4 80242D64 0C00CD4A */  jal       get_game_mode
/* 1360A8 80242D68 00000000 */   nop      
/* 1360AC 80242D6C 00021400 */  sll       $v0, $v0, 0x10
/* 1360B0 80242D70 00021403 */  sra       $v0, $v0, 0x10
/* 1360B4 80242D74 2403000D */  addiu     $v1, $zero, 0xd
/* 1360B8 80242D78 14430024 */  bne       $v0, $v1, .L80242E0C
/* 1360BC 80242D7C 00000000 */   nop      
.L80242D80:
/* 1360C0 80242D80 8E220000 */  lw        $v0, ($s1)
/* 1360C4 80242D84 10400018 */  beqz      $v0, .L80242DE8
/* 1360C8 80242D88 00000000 */   nop      
.L80242D8C:
/* 1360CC 80242D8C 24040016 */  addiu     $a0, $zero, 0x16
/* 1360D0 80242D90 2406FFFF */  addiu     $a2, $zero, -1
/* 1360D4 80242D94 0080282D */  daddu     $a1, $a0, $zero
/* 1360D8 80242D98 3C038016 */  lui       $v1, %hi(D_8015A010)
/* 1360DC 80242D9C 2463A010 */  addiu     $v1, $v1, %lo(D_8015A010)
.L80242DA0:
/* 1360E0 80242DA0 80620003 */  lb        $v0, 3($v1)
/* 1360E4 80242DA4 10460003 */  beq       $v0, $a2, .L80242DB4
/* 1360E8 80242DA8 00000000 */   nop      
/* 1360EC 80242DAC 54450006 */  bnel      $v0, $a1, .L80242DC8
/* 1360F0 80242DB0 24840001 */   addiu    $a0, $a0, 1
.L80242DB4:
/* 1360F4 80242DB4 90620000 */  lbu       $v0, ($v1)
/* 1360F8 80242DB8 30420008 */  andi      $v0, $v0, 8
/* 1360FC 80242DBC 14400006 */  bnez      $v0, .L80242DD8
/* 136100 80242DC0 2882002C */   slti     $v0, $a0, 0x2c
/* 136104 80242DC4 24840001 */  addiu     $a0, $a0, 1
.L80242DC8:
/* 136108 80242DC8 2882002C */  slti      $v0, $a0, 0x2c
/* 13610C 80242DCC 1440FFF4 */  bnez      $v0, .L80242DA0
/* 136110 80242DD0 24630020 */   addiu    $v1, $v1, 0x20
/* 136114 80242DD4 2882002C */  slti      $v0, $a0, 0x2c
.L80242DD8:
/* 136118 80242DD8 14400003 */  bnez      $v0, .L80242DE8
/* 13611C 80242DDC 00000000 */   nop      
/* 136120 80242DE0 3C018025 */  lui       $at, %hi(D_8024EFB4)
/* 136124 80242DE4 AC20EFB4 */  sw        $zero, %lo(D_8024EFB4)($at)
.L80242DE8:
/* 136128 80242DE8 3C018025 */  lui       $at, %hi(gPauseMenuTargetPosX)
/* 13612C 80242DEC AC32EFA8 */  sw        $s2, %lo(gPauseMenuTargetPosX)($at)
/* 136130 80242DF0 3C018025 */  lui       $at, %hi(gPauseMenuCursorPosX)
/* 136134 80242DF4 AC32EF9C */  sw        $s2, %lo(gPauseMenuCursorPosX)($at)
/* 136138 80242DF8 3C018025 */  lui       $at, %hi(gPauseMenuTargetPosY)
/* 13613C 80242DFC AC33EFAC */  sw        $s3, %lo(gPauseMenuTargetPosY)($at)
/* 136140 80242E00 3C018025 */  lui       $at, %hi(gPauseMenuCursorPosY)
/* 136144 80242E04 08090B93 */  j         .L80242E4C
/* 136148 80242E08 AC33EFA0 */   sw       $s3, %lo(gPauseMenuCursorPosY)($at)
.L80242E0C:
/* 13614C 80242E0C 92020000 */  lbu       $v0, ($s0)
/* 136150 80242E10 30420008 */  andi      $v0, $v0, 8
/* 136154 80242E14 1440000D */  bnez      $v0, .L80242E4C
/* 136158 80242E18 2402FFFF */   addiu    $v0, $zero, -1
/* 13615C 80242E1C 82040003 */  lb        $a0, 3($s0)
/* 136160 80242E20 10820006 */  beq       $a0, $v0, .L80242E3C
/* 136164 80242E24 00041140 */   sll      $v0, $a0, 5
/* 136168 80242E28 00541021 */  addu      $v0, $v0, $s4
/* 13616C 80242E2C 90420000 */  lbu       $v0, ($v0)
/* 136170 80242E30 30420008 */  andi      $v0, $v0, 8
/* 136174 80242E34 14400005 */  bnez      $v0, .L80242E4C
/* 136178 80242E38 00000000 */   nop      
.L80242E3C:
/* 13617C 80242E3C 3C018025 */  lui       $at, %hi(gPauseMenuTargetPosX)
/* 136180 80242E40 AC32EFA8 */  sw        $s2, %lo(gPauseMenuTargetPosX)($at)
/* 136184 80242E44 3C018025 */  lui       $at, %hi(gPauseMenuTargetPosY)
/* 136188 80242E48 AC33EFAC */  sw        $s3, %lo(gPauseMenuTargetPosY)($at)
.L80242E4C:
/* 13618C 80242E4C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 136190 80242E50 8FB40020 */  lw        $s4, 0x20($sp)
/* 136194 80242E54 8FB3001C */  lw        $s3, 0x1c($sp)
/* 136198 80242E58 8FB20018 */  lw        $s2, 0x18($sp)
/* 13619C 80242E5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1361A0 80242E60 8FB00010 */  lw        $s0, 0x10($sp)
/* 1361A4 80242E64 03E00008 */  jr        $ra
/* 1361A8 80242E68 27BD0028 */   addiu    $sp, $sp, 0x28
