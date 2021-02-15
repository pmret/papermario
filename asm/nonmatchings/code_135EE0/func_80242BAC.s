.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BAC
/* 135EEC 80242BAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 135EF0 80242BB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 135EF4 80242BB4 00A0882D */  daddu     $s1, $a1, $zero
/* 135EF8 80242BB8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 135EFC 80242BBC 00C0982D */  daddu     $s3, $a2, $zero
/* 135F00 80242BC0 AFB40020 */  sw        $s4, 0x20($sp)
/* 135F04 80242BC4 3C148016 */  lui       $s4, %hi(gUIPanels)
/* 135F08 80242BC8 26949D50 */  addiu     $s4, $s4, %lo(gUIPanels)
/* 135F0C 80242BCC 00042140 */  sll       $a0, $a0, 5
/* 135F10 80242BD0 AFB20018 */  sw        $s2, 0x18($sp)
/* 135F14 80242BD4 3C128025 */  lui       $s2, %hi(D_8024EFB4)
/* 135F18 80242BD8 2652EFB4 */  addiu     $s2, $s2, %lo(D_8024EFB4)
/* 135F1C 80242BDC AFBF0024 */  sw        $ra, 0x24($sp)
/* 135F20 80242BE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 135F24 80242BE4 8E420000 */  lw        $v0, ($s2)
/* 135F28 80242BE8 14400012 */  bnez      $v0, .L80242C34
/* 135F2C 80242BEC 00948021 */   addu     $s0, $a0, $s4
/* 135F30 80242BF0 0C00CD4A */  jal       get_game_mode
/* 135F34 80242BF4 00000000 */   nop
/* 135F38 80242BF8 00021400 */  sll       $v0, $v0, 0x10
/* 135F3C 80242BFC 00021403 */  sra       $v0, $v0, 0x10
/* 135F40 80242C00 2403000F */  addiu     $v1, $zero, 0xf
/* 135F44 80242C04 10430008 */  beq       $v0, $v1, .L80242C28
/* 135F48 80242C08 00000000 */   nop
/* 135F4C 80242C0C 0C00CD4A */  jal       get_game_mode
/* 135F50 80242C10 00000000 */   nop
/* 135F54 80242C14 00021400 */  sll       $v0, $v0, 0x10
/* 135F58 80242C18 00021403 */  sra       $v0, $v0, 0x10
/* 135F5C 80242C1C 2403000D */  addiu     $v1, $zero, 0xd
/* 135F60 80242C20 1443001C */  bne       $v0, $v1, .L80242C94
/* 135F64 80242C24 00000000 */   nop
.L80242C28:
/* 135F68 80242C28 8E420000 */  lw        $v0, ($s2)
/* 135F6C 80242C2C 10400025 */  beqz      $v0, .L80242CC4
/* 135F70 80242C30 00000000 */   nop
.L80242C34:
/* 135F74 80242C34 24040016 */  addiu     $a0, $zero, 0x16
/* 135F78 80242C38 2406FFFF */  addiu     $a2, $zero, -1
/* 135F7C 80242C3C 0080282D */  daddu     $a1, $a0, $zero
/* 135F80 80242C40 3C038016 */  lui       $v1, %hi(D_8015A010)
/* 135F84 80242C44 2463A010 */  addiu     $v1, $v1, %lo(D_8015A010)
.L80242C48:
/* 135F88 80242C48 80620003 */  lb        $v0, 3($v1)
/* 135F8C 80242C4C 10460003 */  beq       $v0, $a2, .L80242C5C
/* 135F90 80242C50 00000000 */   nop
/* 135F94 80242C54 54450006 */  bnel      $v0, $a1, .L80242C70
/* 135F98 80242C58 24840001 */   addiu    $a0, $a0, 1
.L80242C5C:
/* 135F9C 80242C5C 90620000 */  lbu       $v0, ($v1)
/* 135FA0 80242C60 30420008 */  andi      $v0, $v0, 8
/* 135FA4 80242C64 14400006 */  bnez      $v0, .L80242C80
/* 135FA8 80242C68 2882002C */   slti     $v0, $a0, 0x2c
/* 135FAC 80242C6C 24840001 */  addiu     $a0, $a0, 1
.L80242C70:
/* 135FB0 80242C70 2882002C */  slti      $v0, $a0, 0x2c
/* 135FB4 80242C74 1440FFF4 */  bnez      $v0, .L80242C48
/* 135FB8 80242C78 24630020 */   addiu    $v1, $v1, 0x20
/* 135FBC 80242C7C 2882002C */  slti      $v0, $a0, 0x2c
.L80242C80:
/* 135FC0 80242C80 14400010 */  bnez      $v0, .L80242CC4
/* 135FC4 80242C84 00000000 */   nop
/* 135FC8 80242C88 3C018025 */  lui       $at, %hi(D_8024EFB4)
/* 135FCC 80242C8C 08090B31 */  j         .L80242CC4
/* 135FD0 80242C90 AC20EFB4 */   sw       $zero, %lo(D_8024EFB4)($at)
.L80242C94:
/* 135FD4 80242C94 92020000 */  lbu       $v0, ($s0)
/* 135FD8 80242C98 30420008 */  andi      $v0, $v0, 8
/* 135FDC 80242C9C 14400011 */  bnez      $v0, .L80242CE4
/* 135FE0 80242CA0 2402FFFF */   addiu    $v0, $zero, -1
/* 135FE4 80242CA4 82040003 */  lb        $a0, 3($s0)
/* 135FE8 80242CA8 10820006 */  beq       $a0, $v0, .L80242CC4
/* 135FEC 80242CAC 00041140 */   sll      $v0, $a0, 5
/* 135FF0 80242CB0 00541021 */  addu      $v0, $v0, $s4
/* 135FF4 80242CB4 90420000 */  lbu       $v0, ($v0)
/* 135FF8 80242CB8 30420008 */  andi      $v0, $v0, 8
/* 135FFC 80242CBC 14400009 */  bnez      $v0, .L80242CE4
/* 136000 80242CC0 00000000 */   nop
.L80242CC4:
/* 136004 80242CC4 3C018025 */  lui       $at, %hi(gPauseMenuTargetPosX)
/* 136008 80242CC8 AC31EFA8 */  sw        $s1, %lo(gPauseMenuTargetPosX)($at)
/* 13600C 80242CCC 3C018025 */  lui       $at, %hi(gPauseMenuCursorPosX)
/* 136010 80242CD0 AC31EF9C */  sw        $s1, %lo(gPauseMenuCursorPosX)($at)
/* 136014 80242CD4 3C018025 */  lui       $at, %hi(gPauseMenuTargetPosY)
/* 136018 80242CD8 AC33EFAC */  sw        $s3, %lo(gPauseMenuTargetPosY)($at)
/* 13601C 80242CDC 3C018025 */  lui       $at, %hi(D_8024EFA0)
/* 136020 80242CE0 AC33EFA0 */  sw        $s3, %lo(D_8024EFA0)($at)
.L80242CE4:
/* 136024 80242CE4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 136028 80242CE8 8FB40020 */  lw        $s4, 0x20($sp)
/* 13602C 80242CEC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 136030 80242CF0 8FB20018 */  lw        $s2, 0x18($sp)
/* 136034 80242CF4 8FB10014 */  lw        $s1, 0x14($sp)
/* 136038 80242CF8 8FB00010 */  lw        $s0, 0x10($sp)
/* 13603C 80242CFC 03E00008 */  jr        $ra
/* 136040 80242D00 27BD0028 */   addiu    $sp, $sp, 0x28
