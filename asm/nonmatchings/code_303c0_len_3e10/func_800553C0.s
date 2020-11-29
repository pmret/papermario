.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800553C0
/* 307C0 800553C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 307C4 800553C4 34858000 */  ori       $a1, $a0, 0x8000
/* 307C8 800553C8 0000302D */  daddu     $a2, $zero, $zero
/* 307CC 800553CC 3C02800A */  lui       $v0, %hi(D_8009A640)
/* 307D0 800553D0 8C42A640 */  lw        $v0, %lo(D_8009A640)($v0)
/* 307D4 800553D4 00C0382D */  daddu     $a3, $a2, $zero
/* 307D8 800553D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 307DC 800553DC AFA00010 */  sw        $zero, 0x10($sp)
/* 307E0 800553E0 0C012DB6 */  jal       func_8004B6D8
/* 307E4 800553E4 0040202D */   daddu    $a0, $v0, $zero
/* 307E8 800553E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 307EC 800553EC 03E00008 */  jr        $ra
/* 307F0 800553F0 27BD0020 */   addiu    $sp, $sp, 0x20
