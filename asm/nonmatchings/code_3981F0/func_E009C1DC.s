.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E009C1DC
/* 3983CC E009C1DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3983D0 E009C1E0 3C02E00A */  lui       $v0, %hi(D_E009C220)
/* 3983D4 E009C1E4 2442C220 */  addiu     $v0, $v0, %lo(D_E009C220)
/* 3983D8 E009C1E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3983DC E009C1EC 24020001 */  addiu     $v0, $zero, 1
/* 3983E0 E009C1F0 AFA40018 */  sw        $a0, 0x18($sp)
/* 3983E4 E009C1F4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3983E8 E009C1F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3983EC E009C1FC AFA00014 */  sw        $zero, 0x14($sp)
/* 3983F0 E009C200 0C080120 */  jal       func_E0200480
/* 3983F4 E009C204 AFA20010 */   sw       $v0, 0x10($sp)
/* 3983F8 E009C208 8C430000 */  lw        $v1, ($v0)
/* 3983FC E009C20C 34630002 */  ori       $v1, $v1, 2
/* 398400 E009C210 AC430000 */  sw        $v1, ($v0)
/* 398404 E009C214 8FBF0020 */  lw        $ra, 0x20($sp)
/* 398408 E009C218 03E00008 */  jr        $ra
/* 39840C E009C21C 27BD0028 */   addiu    $sp, $sp, 0x28
