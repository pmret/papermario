.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E21C8
/* 3DC4D8 E00E21C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3DC4DC E00E21CC 3C02E00E */  lui       $v0, %hi(D_E00E2218)
/* 3DC4E0 E00E21D0 24422218 */  addiu     $v0, $v0, %lo(D_E00E2218)
/* 3DC4E4 E00E21D4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3DC4E8 E00E21D8 2402000A */  addiu     $v0, $zero, 0xa
/* 3DC4EC E00E21DC AFA20014 */  sw        $v0, 0x14($sp)
/* 3DC4F0 E00E21E0 2402002D */  addiu     $v0, $zero, 0x2d
/* 3DC4F4 E00E21E4 AFA40018 */  sw        $a0, 0x18($sp)
/* 3DC4F8 E00E21E8 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DC4FC E00E21EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 3DC500 E00E21F0 0C080120 */  jal       func_E0200480
/* 3DC504 E00E21F4 AFA20010 */   sw       $v0, 0x10($sp)
/* 3DC508 E00E21F8 8C430000 */  lw        $v1, ($v0)
/* 3DC50C E00E21FC 34630002 */  ori       $v1, $v1, 2
/* 3DC510 E00E2200 AC430000 */  sw        $v1, ($v0)
/* 3DC514 E00E2204 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3DC518 E00E2208 03E00008 */  jr        $ra
/* 3DC51C E00E220C 27BD0028 */   addiu    $sp, $sp, 0x28
