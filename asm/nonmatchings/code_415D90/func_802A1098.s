.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1098
/* 415E28 802A1098 24020064 */  addiu     $v0, $zero, 0x64
/* 415E2C 802A109C 3C01802B */  lui       $at, 0x802b
/* 415E30 802A10A0 A422D008 */  sh        $v0, -0x2ff8($at)
/* 415E34 802A10A4 2402001E */  addiu     $v0, $zero, 0x1e
/* 415E38 802A10A8 3C01802B */  lui       $at, 0x802b
/* 415E3C 802A10AC A022D000 */  sb        $v0, -0x3000($at)
/* 415E40 802A10B0 03E00008 */  jr        $ra
/* 415E44 802A10B4 00000000 */   nop      
