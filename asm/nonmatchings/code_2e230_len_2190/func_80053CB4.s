.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053CB4
/* 2F0B4 80053CB4 24020001 */  addiu     $v0, $zero, 1
/* 2F0B8 80053CB8 10820009 */  beq       $a0, $v0, .L80053CE0
/* 2F0BC 80053CBC 00000000 */   nop      
/* 2F0C0 80053CC0 10800003 */  beqz      $a0, .L80053CD0
/* 2F0C4 80053CC4 24020002 */   addiu    $v0, $zero, 2
/* 2F0C8 80053CC8 14820009 */  bne       $a0, $v0, .L80053CF0
/* 2F0CC 80053CCC 00000000 */   nop      
.L80053CD0:
/* 2F0D0 80053CD0 3C02800A */  lui       $v0, %hi(D_8009A664)
/* 2F0D4 80053CD4 8C42A664 */  lw        $v0, %lo(D_8009A664)($v0)
/* 2F0D8 80053CD8 03E00008 */  jr        $ra
/* 2F0DC 80053CDC ACA20000 */   sw       $v0, ($a1)
.L80053CE0:
/* 2F0E0 80053CE0 3C02800A */  lui       $v0, %hi(D_8009A5FC)
/* 2F0E4 80053CE4 8C42A5FC */  lw        $v0, %lo(D_8009A5FC)($v0)
/* 2F0E8 80053CE8 03E00008 */  jr        $ra
/* 2F0EC 80053CEC ACA20000 */   sw       $v0, ($a1)
.L80053CF0:
/* 2F0F0 80053CF0 03E00008 */  jr        $ra
/* 2F0F4 80053CF4 ACA00000 */   sw       $zero, ($a1)
