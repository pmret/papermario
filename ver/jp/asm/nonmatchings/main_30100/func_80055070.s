.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055070
/* 30470 80055070 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30474 80055074 34858000 */  ori       $a1, $a0, 0x8000
/* 30478 80055078 0000302D */  daddu     $a2, $zero, $zero
/* 3047C 8005507C 3C02800A */  lui       $v0, %hi(D_8009A620)
/* 30480 80055080 8C42A620 */  lw        $v0, %lo(D_8009A620)($v0)
/* 30484 80055084 00C0382D */  daddu     $a3, $a2, $zero
/* 30488 80055088 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3048C 8005508C AFA00010 */  sw        $zero, 0x10($sp)
/* 30490 80055090 0C012CE2 */  jal       func_8004B388
/* 30494 80055094 0040202D */   daddu    $a0, $v0, $zero
/* 30498 80055098 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3049C 8005509C 03E00008 */  jr        $ra
/* 304A0 800550A0 27BD0020 */   addiu    $sp, $sp, 0x20
