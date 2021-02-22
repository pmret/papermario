.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033818
/* EC18 80033818 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EC1C 8003381C 3C02800A */  lui       $v0, %hi(D_8009A630)
/* EC20 80033820 2442A630 */  addiu     $v0, $v0, %lo(D_8009A630)
/* EC24 80033824 AFBF0010 */  sw        $ra, 0x10($sp)
/* EC28 80033828 8C430000 */  lw        $v1, ($v0)
/* EC2C 8003382C 34630008 */  ori       $v1, $v1, 8
/* EC30 80033830 0C017F54 */  jal       func_8005FD50
/* EC34 80033834 AC430000 */   sw       $v1, ($v0)
/* EC38 80033838 8FBF0010 */  lw        $ra, 0x10($sp)
/* EC3C 8003383C 24020005 */  addiu     $v0, $zero, 5
/* EC40 80033840 3C01800A */  lui       $at, %hi(D_8009E710)
/* EC44 80033844 A022E710 */  sb        $v0, %lo(D_8009E710)($at)
/* EC48 80033848 03E00008 */  jr        $ra
/* EC4C 8003384C 27BD0018 */   addiu    $sp, $sp, 0x18
