.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_47F0B0
/* 47F0B0 80218000 24020001 */  addiu     $v0, $zero, 1
/* 47F0B4 80218004 3C018011 */  lui       $at, %hi(gPlayerData+0x12)
/* 47F0B8 80218008 A022F2A2 */  sb        $v0, %lo(gPlayerData+0x12)($at)
/* 47F0BC 8021800C 03E00008 */  jr        $ra
/* 47F0C0 80218010 24020002 */   addiu    $v0, $zero, 2
/* 47F0C4 80218014 00000000 */  nop       
/* 47F0C8 80218018 00000000 */  nop       
/* 47F0CC 8021801C 00000000 */  nop       
