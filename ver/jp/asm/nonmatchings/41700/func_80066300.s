.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066300
/* 41700 80066300 3C01800A */  lui       $at, %hi(D_8009A5E8)
/* 41704 80066304 AC24A5E8 */  sw        $a0, %lo(D_8009A5E8)($at)
/* 41708 80066308 3C01800A */  lui       $at, %hi(D_8009A5EC)
/* 4170C 8006630C 03E00008 */  jr        $ra
/* 41710 80066310 AC25A5EC */   sw       $a1, %lo(D_8009A5EC)($at)
/* 41714 80066314 00000000 */  nop
/* 41718 80066318 00000000 */  nop
/* 4171C 8006631C 00000000 */  nop
