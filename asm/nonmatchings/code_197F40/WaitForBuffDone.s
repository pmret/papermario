.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel WaitForBuffDone
/* 19FA2C 8027114C 3C02802A */  lui       $v0, %hi(D_8029FBD4)
/* 19FA30 80271150 8042FBD4 */  lb        $v0, %lo(D_8029FBD4)($v0)
/* 19FA34 80271154 2C420001 */  sltiu     $v0, $v0, 1
/* 19FA38 80271158 03E00008 */  jr        $ra
/* 19FA3C 8027115C 00021040 */   sll      $v0, $v0, 1
