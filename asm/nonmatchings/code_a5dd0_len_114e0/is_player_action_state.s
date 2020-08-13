.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel is_player_action_state
/* 0A72B0 80110BB0 00041600 */  sll   $v0, $a0, 0x18
/* 0A72B4 80110BB4 3C038011 */  lui   $v1, 0x8011
/* 0A72B8 80110BB8 8063F07C */  lb    $v1, -0xf84($v1)
/* 0A72BC 80110BBC 00021603 */  sra   $v0, $v0, 0x18
/* 0A72C0 80110BC0 00431026 */  xor   $v0, $v0, $v1
/* 0A72C4 80110BC4 03E00008 */  jr    $ra
/* 0A72C8 80110BC8 2C420001 */   sltiu $v0, $v0, 1

