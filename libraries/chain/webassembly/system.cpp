#include <eosio/chain/webassembly/interface.hpp>

namespace eosio { namespace chain { namespace webassembly {
   /* these are both unfortunate that we didn't make the return type an int64_t */
   uint64_t interface::current_time() {
      return static_cast<uint64_t>( ctx.control.pending_block_time().time_since_epoch().count() );
   }

   uint64_t interface::publication_time() {
      return static_cast<uint64_t>( ctx.trx_context.published.time_since_epoch().count() );
   }

   bool interface::is_feature_activated( const digest_type& feature_digest ) {
      return ctx.control.is_protocol_feature_activated( feature_digest );
   }

   name interface::get_sender() {
      return ctx.get_sender();
   }
}}} // ns eosio::chain::webassembly