.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B3D0
/* 467D0 8006B3D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 467D4 8006B3D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 467D8 8006B3D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 467DC 8006B3DC 0C01ACD0 */  jal       func_8006B340
/* 467E0 8006B3E0 00808021 */   addu     $s0, $a0, $zero
/* 467E4 8006B3E4 3C038009 */  lui       $v1, %hi(D_80095890)
/* 467E8 8006B3E8 8C635890 */  lw        $v1, %lo(D_80095890)($v1)
/* 467EC 8006B3EC 00701825 */  or        $v1, $v1, $s0
/* 467F0 8006B3F0 3C018009 */  lui       $at, %hi(D_80095890)
/* 467F4 8006B3F4 AC235890 */  sw        $v1, %lo(D_80095890)($at)
/* 467F8 8006B3F8 0C01ACEC */  jal       func_8006B3B0
/* 467FC 8006B3FC 00402021 */   addu     $a0, $v0, $zero
/* 46800 8006B400 8FBF0014 */  lw        $ra, 0x14($sp)
/* 46804 8006B404 8FB00010 */  lw        $s0, 0x10($sp)
/* 46808 8006B408 03E00008 */  jr        $ra
/* 4680C 8006B40C 27BD0018 */   addiu    $sp, $sp, 0x18
