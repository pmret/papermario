.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_item_entity_flags
/* CA888 80134188 3C028015 */  lui       $v0, 0x8015
/* CA88C 8013418C 8C4265A0 */  lw        $v0, 0x65a0($v0)
/* CA890 80134190 00042080 */  sll       $a0, $a0, 2
/* CA894 80134194 00822021 */  addu      $a0, $a0, $v0
/* CA898 80134198 8C830000 */  lw        $v1, ($a0)
/* CA89C 8013419C 8C620000 */  lw        $v0, ($v1)
/* CA8A0 801341A0 00052827 */  nor       $a1, $zero, $a1
/* CA8A4 801341A4 00451024 */  and       $v0, $v0, $a1
/* CA8A8 801341A8 03E00008 */  jr        $ra
/* CA8AC 801341AC AC620000 */   sw       $v0, ($v1)
